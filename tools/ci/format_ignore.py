# File      : format_ignore.py
# This file is part of RT-Thread RTOS
# COPYRIGHT (C) 2006 - 2015, RT-Thread Development Team
#
# Change Logs:
# Date           Author       Notes
# 2023-05-10     dejavudwh    first version

import os
import yaml
import argparse

IGNORE_FORMAT_FILENAME = ".ignore_format.yml"
OUTPUT_FILENAME = "ignore_files.txt"
REPO_PATH  = ""

def add_file(path):
	with open(OUTPUT_FILENAME, 'a') as output_file:
		path = path.strip()[len(REPO_PATH) + 1:]
		output_file.write(path + '\n')

def add_dir(path):
	for root, dirs, files in os.walk(path):
		for file in files:
			abs_file_path = os.path.abspath(os.path.join(root, file))
			with open(OUTPUT_FILENAME, 'a') as output_file:
				abs_file_path = abs_file_path.strip()[len(REPO_PATH) + 1:]
				output_file.write(abs_file_path + '\n')

def process_ignore_format_file(ignore_file_path, root_path):
	with open(ignore_file_path, 'r') as f:
		ignore_data = yaml.safe_load(f)
		dir_path = ignore_data.get('dir_path', [])
		file_path = ignore_data.get('file_path', [])
		if dir_path != None:
			for path in dir_path:
				abs_path = os.path.abspath(os.path.join(ignore_file_path + "/../", path))
				add_dir(abs_path)
		if file_path != None:
			for path in file_path:
				abs_path = os.path.abspath(os.path.join(ignore_file_path + "/../", path))
				add_file(abs_path)

if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='Process a path and find ignore_format.yml files')
	parser.add_argument('path', type=str, help='path to process')
	args = parser.parse_args()
	REPO_PATH = args.path 
 
	print("repo path is " + REPO_PATH)
	print("In the file that is generating the list of files to be ignored by cppcheck!")

	for root, dirs, files in os.walk(REPO_PATH):
		if IGNORE_FORMAT_FILENAME in files:
			ignore_file_path = os.path.abspath(os.path.join(root, IGNORE_FORMAT_FILENAME))
			process_ignore_format_file(ignore_file_path, args.path)
   
	print("Complete generation")
