/**************************************************************************//**
*
* @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Change Logs:
* Date            Author           Notes
* 2020-7-4        YCHuang12        First version
*
******************************************************************************/

#include <rtconfig.h>

#if (defined(BSP_USING_TRNG) && defined(RT_HWCRYPTO_USING_RNG))

#include <rtdevice.h>
#include "NuMicro.h"
#include <stdlib.h>

#define NU_CRYPTO_TRNG_NAME "nu_TRNG"

/* Private variables ------------------------------------------------------------*/
static struct rt_mutex s_TRNG_mutex;
static int s_i32TRNGEnable = 0;

static rt_uint32_t nu_trng_run(void)
{
    uint32_t u32RNGValue;
    rt_err_t result;

    result = rt_mutex_take(&s_TRNG_mutex, RT_WAITING_FOREVER);
    RT_ASSERT(result == RT_EOK);

    RNG_Open();

    if (RNG_Random(&u32RNGValue, 1) < 0)
    {
        //Failed, use software rand
        u32RNGValue = rand();
    }

    result = rt_mutex_release(&s_TRNG_mutex);
    RT_ASSERT(result == RT_EOK);

    return u32RNGValue;
}

rt_err_t nu_trng_init(void)
{
    rt_err_t result;

    result = rt_mutex_init(&s_TRNG_mutex, NU_CRYPTO_TRNG_NAME, RT_IPC_FLAG_PRIO);
    RT_ASSERT(result == RT_EOK);

    s_i32TRNGEnable = 1;
    SYS_ResetModule(TRNG_RST);
    return RT_EOK;
}

void nu_trng_open(void)
{
#if defined(NU_PRNG_USE_SEED)
    srand(NU_PRNG_SEED_VALUE);
#else
    srand(rt_tick_get());
#endif
}

rt_uint32_t nu_trng_rand(struct hwcrypto_rng *ctx)
{
    if (!s_i32TRNGEnable)
    {
        uint32_t u32RNGValue;
        //use software rand
        u32RNGValue = rand();
        return u32RNGValue;
    }

    return nu_trng_run();
}

#endif //#if (defined(BSP_USING_TRNG) && defined(RT_HWCRYPTO_USING_RNG))
