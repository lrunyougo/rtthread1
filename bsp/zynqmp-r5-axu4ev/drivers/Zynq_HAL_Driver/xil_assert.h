#ifndef XIL_ASSERT_H /* prevent circular inclusions */
#define XIL_ASSERT_H /* by using protection macros */

#include "xil_types.h"

#ifdef __cplusplus
extern "C"
{
#endif
#define Xil_AssertNonvoid(Expression) RT_ASSERT(Expression)
#define Xil_AssertVoid(Expression)    RT_ASSERT(Expression)
#define Xil_AssertVoidAlways()        RT_ASSERT(0)

#ifdef __cplusplus
}
#endif

#endif /* end of protection macro */
/**
* @} End of "addtogroup common_assert_apis".
*/
