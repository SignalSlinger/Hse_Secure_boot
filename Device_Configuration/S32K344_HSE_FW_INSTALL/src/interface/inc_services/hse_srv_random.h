/**
*   @file    hse_srv_random.h
*
*   @brief   HSE Random Number generator services.
*   @details This file contains the HSE Random Number generator services.
*
*   @addtogroup hse_srv_rng HSE Random Number Generator services
*   @ingroup    class_rng
*   @{
*/
/*==================================================================================================
*
*   Copyright 2019 - 2021 NXP.
*
*   This software is owned or controlled by NXP and may only be used strictly in accordance with 
*   the applicable license terms. By expressly accepting such terms or by downloading, installing, 
*   activating and/or otherwise using the software, you are agreeing that you have read, and that 
*   you agree to comply with and are bound by, such license terms. If you do not agree to 
*   be bound by the applicable license terms, then you may not retain, install, activate or 
*   otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_SRV_RANDOM_H
#define HSE_SRV_RANDOM_H


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "hse_common_types.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** @brief HSE RNG classes.
 *
    @note  Additional entropy (personalization string) is not needed to be provide by user.
           The entropy generated by the TRNG already ensures this with high probability. */
typedef uint8_t hseRngClass_t;

/** @brief DRG.3 class uses the RNG engine with prediction resistance disabled.
 *         This is the most efficient class in terms of performance. */
#define HSE_RNG_CLASS_DRG3 ((hseRngClass_t)0U)
/** @brief DRG.4 (AIS-20/SP800-90A) class uses the RNG engine with  prediction resistance enabled.
 *         Using the prediction resistance will impact the performance, as every
 *         call to Get Random invokes reseed internally. */
#define HSE_RNG_CLASS_DRG4 ((hseRngClass_t)1U)
/** @brief PTG.3 (AIS 31/SP800-90C) class uses the RNG engine with prediction resistance enabled
 *         and will reseed for each 16 bytes of data.
 *         This is the most costly class in terms of performance. */
#define HSE_RNG_CLASS_PTG3 ((hseRngClass_t)2U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief Get random number service. 
 * @note This command can be performed only when the #HSE_STATUS_RNG_INIT_OK bit is set.
 * */
typedef struct
{
    /** @brief   INPUT: The RNG class. */
    hseRngClass_t           rngClass;
    uint8_t                 reserved[3];
    /** @brief   INPUT: Length on the random number in bytes. It should not be more than 2048
     *                  bytes, otherwise an error will be returned by HSE FW.
     */
    uint32_t                randomNumLength;
    /** @brief   OUTPUT: The address where the random number will be stored. */
    HOST_ADDR               pRandomNum;
} hseGetRandomNumSrv_t;


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /* HSE_SRV_RANDOM_H */

/** @} */
