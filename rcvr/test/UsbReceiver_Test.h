///////////////////////////////////////////////////////////////
///  This file defines a class that is used for testing
///  the USB receiver.
///
/// @author
///         $Author: Mike Moore $
///
/// Contact: mike.moore@so.engineering
///
/// Created on: Sunday July 2 2016
///
///////////////////////////////////////////////////////////////
#ifndef USB_RECEIVER_TEST_HH
#define USB_RECEIVER_TEST_HH

#include <limits.h>
#include "gtest/gtest.h"
#include "UsbReceiver.h"

///////////////////////////////////////////////////////////////
/// @class UsbReceiver_Test
/// @ingroup Communication
/// @brief Definition of test class for performing unit-tests
///        of the USB receiver.
///////////////////////////////////////////////////////////////
class UsbReceiver_Test : public testing::Test{

 public:
  //////////////////////////////////////////////////////////
  /// @brief The default c'tor constructs the UsbReceiver_Test
  ///        class.
  ////////////////////////////////////////////////////////////
  UsbReceiver_Test();
  //////////////////////////////////////////////////////////
  /// @brief The default d'tor destructs the UsbReceiver_Test
  ///        class.
  ////////////////////////////////////////////////////////////
  ~UsbReceiver_Test();

 protected:
  ////////////////////////////////////////////////////////////
  /// @brief Unit-test setup routine.
  ////////////////////////////////////////////////////////////
  virtual void SetUp();
  ////////////////////////////////////////////////////////////
  /// @brief Unit-test tear down routine.
  ////////////////////////////////////////////////////////////
  virtual void TearDown();
  ////////////////////////////////////////////////////////////
  /// @brief Virtual comm port handle.
  ////////////////////////////////////////////////////////////
  int VirtualCommPortHandle;
  ////////////////////////////////////////////////////////////
  /// @brief Name of the virtual comm device.
  ///        Example: "/dev/pts/21"
  ////////////////////////////////////////////////////////////
  std::string VirtualCommPortName;
  ////////////////////////////////////////////////////////////
  /// @brief Instance of class under test.
  ////////////////////////////////////////////////////////////
  UsbReceiver TestArticle;
  ////////////////////////////////////////////////////////////
  /// @brief Unit-test tolerance for floating pt comparisons.
  ////////////////////////////////////////////////////////////
  float Tolerance;

};

#endif  // USB_RECEIVER_TEST_HH