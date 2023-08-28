#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <ESP8266SMTP.h>

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// NTP settings
const char* ntpServer = "pool.ntp.org";
const long utcOffsetInSeconds = -21600; // UTC-6:00 for Mountain Time during Daylight Saving Time

// Email settings
const char* smtpServer = "smtp.gmail.com";
const int smtpPort = 465;
const char* emailSender = "your_sender_email@gmail.com";
const char* emailPassword = "your_sender_email_password";
const char* emailRecipient = "recipient_email@example.com";

// Pin for the signal to Arduino Nano
const int signalPin = 1;  // GPIO1 (TX pin)

// NTPClient instance
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer, utcOffsetInSeconds);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize NTPClient
  timeClient.begin();

  // Configure pin for the signal
  pinMode(signalPin, OUTPUT);

  // Swap the serial pins to use GPIO1 (TX) as Serial output
  Serial.swap();
}

void loop() {
  // Update NTPClient
  timeClient.update();

  // Check if it's the predefined time to send the signal
  if (timeClient.getHours() == 12 && timeClient.getMinutes() == 0 && timeClient.getSeconds() == 0) {
    int durationInSeconds = 10;  // Duration for the light to be turned on

    // Send signal to Arduino Nano
    Serial.print("SIGNAL:");
    Serial.println(durationInSeconds);

    // Send email with the time and duration
    sendEmail(timeClient.getFormattedTime(), durationInSeconds);

    delay(1000);  // Wait for 1 second before sending the signal again (to avoid multiple signals)
  }
}

void sendEmail(String time, int duration) {
  Serial.println("Sending email...");

  // Create an SMTPClient object
  SMTPClient smtp(smtpServer, smtpPort, emailSender, emailPassword);

  // Start connection
  if (!smtp.connect()) {
    Serial.println("Connection failed!");
    return;
  }

  // Compose email subject and body
  String subject = "Light turned on at " + time;
  String body = "The light was turned on for " + String(duration) + " seconds.";

  // Send email
  if (!smtp.send(emailSender, emailRecipient, subject, body)) {
    Serial.println("Failed to send email!");
  }

  // Disconnect from the SMTP server
  smtp.disconnect();

  Serial.println("Email sent!");
}
