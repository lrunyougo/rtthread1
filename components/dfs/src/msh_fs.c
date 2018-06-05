/*
 *  internal commands for RT-Thread module shell
 *
 * COPYRIGHT (C) 2013-2015, Shanghai Real-Thread Technology Co., Ltd
 *
 *  This file is part of RT-Thread (http://www.rt-thread.org)
 *  Maintainer: bernard.xiong <bernard.xiong at gmail.com>
 *
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2013-03-30     Bernard      the first verion for FinSH
 * 2015-08-28     Bernard      Add mkfs command.
 */

#include <rtthread.h>
#include <finsh.h>

#ifdef FINSH_USING_MSH
#ifdef RT_USING_DFS
#include <dfs_posix.h>

#ifdef DFS_USING_WORKDIR
extern char working_directory[];
#endif

static void ls(const char *pathname)
{
    struct stat st;
    char *fullpath, *path;
    DIR *dir;
    struct dirent *dirent;

    dir = opendir(path);
    if (dir != 0)
    {
        rt_kprintf("Directory %s:\n", path);
        do
        {
            dirent = readdir(dir);

            if (dirent != 0)
            {
                rt_memset(&stat, 0, sizeof(struct stat));

                /* build full path for each file */
                fullpath = dfs_normalize_path(path, dirent->d_name);
                if (fullpath == NULL)
                    break;

                if (stat(fullpath, &st) == 0)
                {
                    rt_kprintf("%-20s", dirent->d_name);
                    if (S_ISDIR(st.st_mode))
                    {
                        rt_kprintf("%-25s\n", "<DIR>");
                    }
                    else
                    {
                        rt_kprintf("%-25lu\n", st.st_size);
                    }
                }
                else
                    rt_kprintf("BAD file: %s\n", dirent->d_name);
                rt_free(fullpath);
            }
        }while(dirent != 0);

        closedir(dir);
    }
    else
    {
        rt_kprintf("No such directory\n");
    }

    if (pathname == NULL)
        rt_free(path);
}

static int cmd_ls(int argc, char **argv)
{
    if (argc == 1)
    {
#ifdef DFS_USING_WORKDIR
        ls(working_directory);
#else
        ls("/");
#endif
    }
    else
    {
        ls(argv[1]);
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_ls, __cmd_ls, List information about the FILEs.);

static void copy(const char *src, const char *dst)
{
    int sfd, dfd;
    rt_uint8_t *block_ptr;
    int read_bytes;

#define BUF_SZ    2048

    block_ptr = rt_malloc(BUF_SZ);
    if (block_ptr == NULL)
    {
        rt_kprintf("out of memory\n");
        return;
    }

    sfd = open(src, O_RDONLY, 0);
    if (sfd < 0)
    {
        rt_free(block_ptr);
        rt_kprintf("Read %s failed\n", src);
        return;
    }
    dfd = open(dst, O_WRONLY | O_CREAT, 0);
    if (dfd < 0)
    {
        rt_free(block_ptr);
        close(sfd);

        rt_kprintf("Write %s failed\n", dst);
        return;
    }

    do
    {
        read_bytes = read(sfd, block_ptr, BUF_SZ);
        if (read_bytes > 0)
        {
            int length;

            length = write(dfd, block_ptr, read_bytes);
            if (length != read_bytes)
            {
                /* write failed. */
                rt_kprintf("Write file data failed, errno=%d\n", length);
                break;
            }
        }
    } while (read_bytes > 0);

    close(sfd);
    close(dfd);
    rt_free(block_ptr);
}

static int cmd_cp(int argc, char **argv)
{
    if (argc != 3)
    {
        rt_kprintf("Usage: cp SOURCE DEST\n");
        rt_kprintf("Copy SOURCE to DEST.\n");
    }
    else
    {
        copy(argv[1], argv[2]);
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_cp, __cmd_cp, Copy SOURCE to DEST.);

static int cmd_mv(int argc, char **argv)
{
    if (argc != 3)
    {
        rt_kprintf("Usage: mv SOURCE DEST\n");
        rt_kprintf("Rename SOURCE to DEST, or move SOURCE(s) to DIRECTORY.\n");
    }
    else
    {
        int fd;
        char *dest = RT_NULL;

        rt_kprintf("%s => %s\n", argv[1], argv[2]);

        fd = open(argv[2], O_DIRECTORY, 0);
        if (fd >= 0)
        {
            char *src;

            close(fd);

            /* it's a directory */
            dest = (char *)rt_malloc(DFS_PATH_MAX);
            if (dest == RT_NULL)
            {
                rt_kprintf("out of memory\n");
                return -RT_ENOMEM;
            }

            src = argv[1] + rt_strlen(argv[1]);
            while (src != argv[1])
            {
                if (*src == '/') break;
                src --;
            }

            rt_snprintf(dest, DFS_PATH_MAX - 1, "%s/%s", argv[2], src);
        }
        else
        {
            fd = open(argv[2], O_RDONLY, 0);
            if (fd >= 0)
            {
                close(fd);

                unlink(argv[2]);
            }

            dest = argv[2];
        }

        rename(argv[1], dest);
        if (dest != RT_NULL && dest != argv[2]) rt_free(dest);
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_mv, __cmd_mv, Rename SOURCE to DEST.);

static void cat(const char *filename)
{
    int length;
    char buffer[81];
    int fd;

    if ((fd = open(filename, O_RDONLY)) < 0)
    {
        rt_kprintf("Open %s failed\n", filename);
        return;
    }

    do
    {
        rt_memset(buffer, 0, sizeof(buffer));
        length = read(fd, buffer, sizeof(buffer)-1);
        if (length > 0)
        {
            rt_kprintf("%s", buffer);
        }
    }while (length > 0);

    close(fd);
}

static int cmd_cat(int argc, char **argv)
{
    int index;

    if (argc == 1)
    {
        rt_kprintf("Usage: cat [FILE]...\n");
        rt_kprintf("Concatenate FILE(s)\n");
        return 0;
    }

    for (index = 1; index < argc; index ++)
    {
        cat(argv[index]);
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_cat, __cmd_cat, Concatenate FILE(s));

static int cmd_rm(int argc, char **argv)
{
    int index;

    if (argc == 1)
    {
        rt_kprintf("Usage: rm FILE...\n");
        rt_kprintf("Remove (unlink) the FILE(s).\n");
        return 0;
    }

    for (index = 1; index < argc; index ++)
    {
        unlink(argv[index]);
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_rm, __cmd_rm, Remove(unlink) the FILE(s).);

#ifdef DFS_USING_WORKDIR
static int cmd_cd(int argc, char **argv)
{
    if (argc == 1)
    {
        rt_kprintf("%s\n", working_directory);
    }
    else if (argc == 2)
    {
        if (chdir(argv[1]) != 0)
        {
            rt_kprintf("No such directory: %s\n", argv[1]);
        }
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_cd, __cmd_cd, Change the shell working directory.);

static int cmd_pwd(int argc, char **argv)
{
    rt_kprintf("%s\n", working_directory);
    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_pwd, __cmd_pwd, Print the name of the current working directory.);
#endif

static int cmd_mkdir(int argc, char **argv)
{
    if (argc == 1)
    {
        rt_kprintf("Usage: mkdir [OPTION] DIRECTORY\n");
        rt_kprintf("Create the DIRECTORY, if they do not already exist.\n");
    }
    else
    {
        mkdir(argv[1], 0);
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_mkdir, __cmd_mkdir, Create the DIRECTORY.);

static int cmd_mkfs(int argc, char **argv)
{
    int result = 0;
    char *type = "elm"; /* use the default file system type as 'fatfs' */

    if (argc == 2)
    {
        result = dfs_mkfs(type, argv[1]);
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "-t") == 0)
        {
            type = argv[2];
            result = dfs_mkfs(type, argv[3]);
        }
    }
    else
    {
        rt_kprintf("Usage: mkfs [-t type] device\n");
        return 0;
    }

    if (result != RT_EOK)
    {
        rt_kprintf("mkfs failed, result=%d\n", result);
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_mkfs, __cmd_mkfs, format disk with file system);

static int df(const char *path)
{
    int result;
    int minor = 0;
    long long cap;
    struct statfs buffer;

    int unit_index = 0;
    char *unit_str[] = {"KB", "MB", "GB"};

    result = statfs(path ? path : NULL, &buffer);
    if (result != 0)
    {
        rt_kprintf("dfs_statfs failed.\n");
        return -1;
    }

    cap = ((long long)buffer.f_bsize) * ((long long)buffer.f_bfree) / 1024LL;
    for (unit_index = 0; unit_index < 2; unit_index ++)
    {
        if (cap < 1024) break;

        minor = (cap % 1024) * 10 / 1024; /* only one decimal point */
        cap = cap / 1024;
    }

    rt_kprintf("disk free: %d.%d %s [ %d block, %d bytes per block ]\n",
        (unsigned long)cap, minor, unit_str[unit_index], buffer.f_bfree, buffer.f_bsize);
    return 0;
}

static int cmd_df(int argc, char** argv)
{
    if (argc != 2)
    {
        df("/");
    }
    else
    {
        if ((strcmp(argv[1], "--help") == 0) || (strcmp(argv[1], "-h") == 0))
        {
            rt_kprintf("df [path]\n");
        }
        else
        {
            df(argv[1]);
        }
    }

    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_df, __cmd_df, disk free);

#endif
#endif
