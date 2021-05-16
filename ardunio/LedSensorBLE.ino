/*
Based on a code from OpenSourceRF.com.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 See the GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <RFduinoBLE.h>


int led = 3; // GPIO 3 is used here
int sensor = 5; // GPIO 5 is used here
int threshold = 900; // Check serial monitor for the correct threshold

void setup() {
Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);

  // this is the data we want to appear in the advertisement
  // (if the deviceName and advertisementData are too long to fix into the 31 byte
  // ble advertisement packet, then the advertisementData is truncated first down to
  // a single byte, then it will truncate the deviceName)
 RFduinoBLE.advertisementData = "ledbtn";
  
  // start advertising so our smartphone can scan and find the device
  RFduinoBLE.begin();
}

void loop() {
  // read the value of the LDR
  int sensorValue = analogRead(sensor);

  // The LDR will send data to the smartphone Application
  // If the measured value is lower than the threshold, the Arduino will send a "1" to the App
  // The App will then send a "1" to the RFduino causing the LED to light up
  if (sensorValue > threshold) {
        RFduinoBLE.send(0);
        delay(1000);
  } else {
        RFduinoBLE.send(1);
        delay(1000);
  }
    
Serial.println(sensorValue);
delay(10);

}

void RFduinoBLE_onDisconnect()
{
  // don't leave the led on if they disconnect
  digitalWrite(led, LOW);
}

void RFduinoBLE_onReceive(char *data, int len)
{
  // if the first byte is 0x01 / on / true
 if (data[0])
   digitalWrite(led, HIGH);
 else
   digitalWrite(led, LOW);
}
