///////////////////////////////////////////////////////////////
///  This file defines a class that is used to implement the
///  USB receiver Linux driver.
///
/// @author
///         $Author: Mike Moore $
///
/// Contact: mike.moore@so.engineering
///
/// Created on: Sunday July 2 2016
///
///////////////////////////////////////////////////////////////
#ifndef USB_RECEIVER_HH
#define USB_RECEIVER_HH

#include "UnixSerialChannel.h"

///////////////////////////////////////////////////////////////
/// @class UsbReceiver
/// @ingroup Communication
/// @brief Definition of class that implements a Unix serial
///        communication channel.
///////////////////////////////////////////////////////////////
class UsbReceiver : public UnixSerialChannel { 

 public:
  ////////////////////////////////////////////////////////////
  /// @brief The default c'tor constructs the UsbReceiver
  ///        class.
  ////////////////////////////////////////////////////////////
  UsbReceiver();
  ////////////////////////////////////////////////////////////
  /// @brief The default d'tor destructs the UsbReceiver
  ///        class.
  ////////////////////////////////////////////////////////////
  ~UsbReceiver();
  ////////////////////////////////////////////////////////////
  /// @brief Transmits and receives packets to/from the USB 
  ///        device.
  ////////////////////////////////////////////////////////////
  void RunComm();
  ////////////////////////////////////////////////////////////
  /// @brief Transmit the command packet.
  ////////////////////////////////////////////////////////////
  void Tx();
  ////////////////////////////////////////////////////////////
  /// @brief Set the normalized voltage command.
  ////////////////////////////////////////////////////////////
  float NormalizedVoltage;
  ////////////////////////////////////////////////////////////
  /// @brief Set the Chupacabra second command.
  ////////////////////////////////////////////////////////////
  float SecondCommand;
  ////////////////////////////////////////////////////////////
  /// @brief Estimated motor shaft position
  ////////////////////////////////////////////////////////////
  float Position;
  ////////////////////////////////////////////////////////////
  /// @brief Estimated motor shaft velocity
  ////////////////////////////////////////////////////////////
  float Velocity;
  ////////////////////////////////////////////////////////////
  /// @brief New tlm var
  ////////////////////////////////////////////////////////////
  float NewTelemetry;
 protected:
  ////////////////////////////////////////////////////////////
  /// @brief Number of frames to wait after Tx() before 
  ///        calling Rx().
  ////////////////////////////////////////////////////////////
  int RxWaitCycles;
  ////////////////////////////////////////////////////////////
  /// @brief Number of frames to wait on a comm reset.
  ////////////////////////////////////////////////////////////
  int ResetWaitCycles;
 private:
  ////////////////////////////////////////////////////////////
  /// @brief Called after Tx. This function will wait/block
  ///        a short amount of time to allow the USB device to 
  ///        send its response to commands.
  ////////////////////////////////////////////////////////////
  void WaitToRx();
  ////////////////////////////////////////////////////////////
  /// @brief Helper function to limit a float to a range.
  ////////////////////////////////////////////////////////////
  float clip(float n, float lower, float upper);

};

#endif  // USB_RECEIVER_HH