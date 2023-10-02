#include "service_defs.h"
#include "GattCharacteristic.h"
#include "GattService.h"
#include "GattUuid.h"

namespace ggk {

void registerServices(DBusObject &target) {
  target.gattServiceBegin("device", GattUuid("180A"))
      .gattCharacteristicBegin("demo", "2A09", {"read"})
      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
        const char *pTextString =
            self.getDataPointer<const char *>("/device/demo", "null");
        self.methodReturnValue(pInvocation, pTextString, true);
      })
      .gattCharacteristicEnd()
      .gattServiceEnd();

  // We're going to build off of this object, so we need to get a reference to
  // the instance of the object as it resides in the list (and not the object
  // that would be added to the list.)
//  target
//      // Service: Device Information (0x180A)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.service.device_information.xml

//      .gattServiceBegin("device", "180A")

//      // Characteristic: Manufacturer Name String (0x2A29)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.manufacturer_name_string.xml
//      .gattCharacteristicBegin("mfgr_name", "2A29", {"read"})

//      // Standard characteristic "ReadValue" method call
//      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        self.methodReturnValue(pInvocation, "Acme Inc.", true);
//      })

//      .gattCharacteristicEnd()

//      // Characteristic: Model Number String (0x2A24)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.model_number_string.xml
//      .gattCharacteristicBegin("model_num", "2A24", {"read"})

//      // Standard characteristic "ReadValue" method call
//      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        self.methodReturnValue(pInvocation, "Marvin-PA", true);
//      })

//      .gattCharacteristicEnd()

//      .gattServiceEnd()

//      // Battery Service (0x180F)
//      //
//      // This is a fake battery service that conforms to
//      // org.bluetooth.service.battery_service. For details, see:
//      //
//      //     https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.service.battery_service.xml
//      //
//      // We also handle updates to the battery level from inside the server (see
//      // onUpdatedValue). There is an external method (see main.cpp) that
//      // updates our battery level and posts an update using ggkPushUpdateQueue.
//      // Those updates are used to notify us that our value has changed, which
//      // translates into a call to `onUpdatedValue` from the idleFunc (see
//      // Init.cpp).
//      .gattServiceBegin("battery", "180F")

//      // Characteristic: Battery Level (0x2A19)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.battery_level.xml
//      .gattCharacteristicBegin("level", "2A19", {"read", "notify"})

//      // Standard characteristic "ReadValue" method call
//      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        uint8_t batteryLevel = self.getDataValue<uint8_t>("battery/level", 0);
//        self.methodReturnValue(pInvocation, batteryLevel, true);
//      })

//      // Handle updates to the battery level
//      //
//      // Here we use the onUpdatedValue to set a callback that isn't exposed to
//      // BlueZ, but rather allows us to manage updates to our value. These
//      // updates may have come from our own server or some other source.
//      //
//      // We can handle updates in any way we wish, but the most common use is to
//      // send a change notification.
//      .onUpdatedValue(CHARACTERISTIC_UPDATED_VALUE_CALLBACK_LAMBDA {
//        uint8_t batteryLevel = self.getDataValue<uint8_t>("battery/level", 0);
//        self.sendChangeNotificationValue(pConnection, batteryLevel);
//        return true;
//      })

//      .gattCharacteristicEnd()
//      .gattServiceEnd()

//      // Current Time Service (0x1805)
//      //
//      // This is a time service that conforms to
//      // org.bluetooth.service.current_time. For details, see:
//      //
//      //    https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.service.current_time.xml
//      //
//      // Like the battery service, this also makes use of events. This one
//      // updates the time every tick.
//      //
//      // This showcases the use of events (see the call to .onEvent() below) for
//      // periodic actions. In this case, the action taken is to update time
//      // every tick. This probably isn't a good idea for a production service,
//      // but it has been quite useful for testing to ensure we're connected and
//      // updating.
//      .gattServiceBegin("time", "1805")

//      // Characteristic: Current Time (0x2A2B)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.current_time.xml
//      .gattCharacteristicBegin("current", "2A2B", {"read", "notify"})

//      // Standard characteristic "ReadValue" method call
//      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        self.methodReturnVariant(pInvocation,
//                                 ServerUtils::gvariantCurrentTime(), true);
//      })

//      // Update the time every tick of the periodic timer
//      //
//      // We'll send an change notification to any subscribed clients with the
//      // latest value
//      .onEvent(
//          1, nullptr,
//          CHARACTERISTIC_EVENT_CALLBACK_LAMBDA {
//            self.sendChangeNotificationVariant(
//                pConnection, ServerUtils::gvariantCurrentTime());
//          })

//      .gattCharacteristicEnd()

//      // Characteristic: Local Time Information (0x2A0F)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.characteristic.local_time_information.xml
//      .gattCharacteristicBegin("local", "2A0F", {"read"})

//      // Standard characteristic "ReadValue" method call
//      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        self.methodReturnVariant(pInvocation, ServerUtils::gvariantLocalTime(),
//                                 true);
//      })

//      .gattCharacteristicEnd()
//      .gattServiceEnd()

//      // Custom read/write text string service
//      // (00000001-1E3C-FAD4-74E2-97A033F1BFAA)
//      //
//      // This service will return a text string value (default: 'Hello,
//      // world!'). If the text value is updated, it will notify that the value
//      // has been updated and provide the new text from that point forward.
//      .gattServiceBegin("text", "00000001-1E3C-FAD4-74E2-97A033F1BFAA")

//      // Characteristic: String value (custom:
//      // 00000002-1E3C-FAD4-74E2-97A033F1BFAA)
//      .gattCharacteristicBegin("string", "00000002-1E3C-FAD4-74E2-97A033F1BFAA",
//                               {"read", "write", "notify"})

//      // Standard characteristic "ReadValue" method call
//      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        const char *pTextString =
//            self.getDataPointer<const char *>("text/string", "");
//        self.methodReturnValue(pInvocation, pTextString, true);
//      })

//      // Standard characteristic "WriteValue" method call
//      .onWriteValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        // Update the text string value
//        GVariant *pAyBuffer = g_variant_get_child_value(pParameters, 0);
//        self.setDataPointer(
//            "text/string",
//            Utils::stringFromGVariantByteArray(pAyBuffer).c_str());

//        // Since all of these methods (onReadValue, onWriteValue, onUpdateValue)
//        // are all part of the same Characteristic interface (which just so
//        // happens to be the same interface passed into our self parameter) we
//        // can that parameter to call our own onUpdatedValue method
//        self.callOnUpdatedValue(pConnection, pUserData);

//        // Note: Even though the WriteValue method returns void, it's important
//        // to return like this, so that a dbus "method_return" is sent,
//        // otherwise the client gets an error (ATT error code 0x0e"unlikely").
//        // Only "write-without-response" works without this
//        self.methodReturnVariant(pInvocation, NULL);
//      })

//      // Here we use the onUpdatedValue to set a callback that isn't exposed to
//      // BlueZ, but rather allows us to manage updates to our value. These
//      // updates may have come from our own server or some other source.
//      //
//      // We can handle updates in any way we wish, but the most common use is to
//      // send a change notification.
//      .onUpdatedValue(CHARACTERISTIC_UPDATED_VALUE_CALLBACK_LAMBDA {
//        const char *pTextString =
//            self.getDataPointer<const char *>("text/string", "");
//        self.sendChangeNotificationValue(pConnection, pTextString);
//        return true;
//      })

//      // GATT Descriptor: Characteristic User Description (0x2901)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.characteristic_user_description.xml
//      .gattDescriptorBegin("description", "2901", {"read"})

//      // Standard descriptor "ReadValue" method call
//      .onReadValue(DESCRIPTOR_METHOD_CALLBACK_LAMBDA {
//        const char *pDescription = "A mutable text string used for testing. "
//                                   "Read and write to me, it tickles!";
//        self.methodReturnValue(pInvocation, pDescription, true);
//      })

//      .gattDescriptorEnd()

//      .gattCharacteristicEnd()
//      .gattServiceEnd()

//      // Custom ASCII time string service
//      //
//      // This service will simply return the result of asctime() of the current
//      // local time. It's a nice test service to provide a new value each time
//      // it is read.

//      // Service: ASCII Time (custom: 00000001-1E3D-FAD4-74E2-97A033F1BFEE)
//      .gattServiceBegin("ascii_time", "00000001-1E3D-FAD4-74E2-97A033F1BFEE")

//      // Characteristic: ASCII Time String (custom:
//      // 00000002-1E3D-FAD4-74E2-97A033F1BFEE)
//      .gattCharacteristicBegin("string", "00000002-1E3D-FAD4-74E2-97A033F1BFEE",
//                               {"read"})

//      // Standard characteristic "ReadValue" method call
//      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        // Get our local time string using asctime()
//        time_t timeVal = time(nullptr);
//        struct tm *pTimeStruct = localtime(&timeVal);
//        std::string timeString = Utils::trim(asctime(pTimeStruct));

//        self.methodReturnValue(pInvocation, timeString, true);
//      })

//      // GATT Descriptor: Characteristic User Description (0x2901)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.characteristic_user_description.xml
//      .gattDescriptorBegin("description", "2901", {"read"})

//      // Standard descriptor "ReadValue" method call
//      .onReadValue(DESCRIPTOR_METHOD_CALLBACK_LAMBDA {
//        const char *pDescription = "Returns the local time (as reported by "
//                                   "POSIX asctime()) each time it is read";
//        self.methodReturnValue(pInvocation, pDescription, true);
//      })

//      .gattDescriptorEnd()

//      .gattCharacteristicEnd()
//      .gattServiceEnd()

//      // Custom CPU information service (custom:
//      // 0000B001-1E3D-FAD4-74E2-97A033F1BFEE)
//      //
//      // This is a cheezy little service that reads the CPU info from
//      // /proc/cpuinfo and returns the count and model of the CPU. It may not
//      // work on all platforms, but it does provide yet another example of how
//      // to do things.

//      // Service: CPU Information (custom: 0000B001-1E3D-FAD4-74E2-97A033F1BFEE)
//      .gattServiceBegin("cpu", "0000B001-1E3D-FAD4-74E2-97A033F1BFEE")

//      // Characteristic: CPU Count (custom:
//      // 0000B002-1E3D-FAD4-74E2-97A033F1BFEE)
//      .gattCharacteristicBegin("count", "0000B002-1E3D-FAD4-74E2-97A033F1BFEE",
//                               {"read"})

//      // Standard characteristic "ReadValue" method call
//      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        int16_t cpuCount = 0;
//        ServerUtils::getCpuInfo(cpuCount);
//        self.methodReturnValue(pInvocation, cpuCount, true);
//      })

//      // GATT Descriptor: Characteristic User Description (0x2901)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.characteristic_user_description.xml
//      .gattDescriptorBegin("description", "2901", {"read"})

//      // Standard descriptor "ReadValue" method call
//      .onReadValue(DESCRIPTOR_METHOD_CALLBACK_LAMBDA {
//        const char *pDescription =
//            "This might represent the number of CPUs in the system";
//        self.methodReturnValue(pInvocation, pDescription, true);
//      })

//      .gattDescriptorEnd()

//      .gattCharacteristicEnd()

//      // Characteristic: CPU Model (custom:
//      // 0000B003-1E3D-FAD4-74E2-97A033F1BFEE)
//      .gattCharacteristicBegin("model", "0000B003-1E3D-FAD4-74E2-97A033F1BFEE",
//                               {"read"})

//      // Standard characteristic "ReadValue" method call
//      .onReadValue(CHARACTERISTIC_METHOD_CALLBACK_LAMBDA {
//        int16_t cpuCount = 0;
//        self.methodReturnValue(pInvocation, ServerUtils::getCpuInfo(cpuCount),
//                               true);
//      })

//      // GATT Descriptor: Characteristic User Description (0x2901)
//      //
//      // See:
//      // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.characteristic_user_description.xml
//      .gattDescriptorBegin("description", "2901", {"read"})

//      // Standard descriptor "ReadValue" method call
//      .onReadValue(DESCRIPTOR_METHOD_CALLBACK_LAMBDA {
//        const char *pDescription =
//            "Possibly the model of the CPU in the system";
//        self.methodReturnValue(pInvocation, pDescription, true);
//      })

//      .gattDescriptorEnd()

//      .gattCharacteristicEnd()
//      .gattServiceEnd(); // << -- NOTE THE SEMICOLON
}
}
