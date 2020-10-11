#include "utest.h"
#include "gm_circular_buffer.h"

UTEST(GMCircularBuffer_Init, Initialize_Expect_Zero_Elements) 
{
   GMCircularBuffer_Init();
   EXPECT_EQ(GMCircularBuffer_GetElementCount(), 0);
}


UTEST(GMCircularBuffer_Insert, Insert_One_Element_Expect_One_Element_With_Correct) 
{
  GMMeasurement_Value_t elementInserted = 0xABCD;
  GMMeasurement_Value_t elementRetreived = 0xFFFF;

  GMCircularBuffer_Insert(elementInserted);
  EXPECT_EQ(GMCircularBuffer_GetElementCount(), 1);

  bool isRetreiveOK = GMCircularBuffer_GetElement(&elementRetreived, 0);
  ASSERT_TRUE(isRetreiveOK);
  EXPECT_EQ(elementRetreived, elementInserted);
}



UTEST_MAIN();
