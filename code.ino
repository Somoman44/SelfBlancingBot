#include <Wire.h>
#include <MPU6050.h>
#include <PID_v1.h>

MPU6050 mpu;

// Motor pins
const int ENA = 14;
const int ENB = 32;
const int IN1 = 27;
const int IN2 = 26;
const int IN3 = 25;
const int IN4 = 33;

// PID variables
double setpoint = 0;    // Desired angle (upright)
double input = 0;       // Current angle from MPU6050
double output = 0;      // PID output

double Kp = 35; // Adjust this
double Ki = 0;
double Kd = 1.5;

PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  Serial.begin(115200);

  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // MPU setup
  Wire.begin(21, 22); // SDA, SCL pins for ESP32
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);
  }

  // Apply calibration offsets from your calibration results
  mpu.setXAccelOffset(-188);
  mpu.setYAccelOffset(-277);
  mpu.setZAccelOffset(689);
  mpu.setXGyroOffset(119);
  mpu.setYGyroOffset(40);
  mpu.setZGyroOffset(-3);

  pid.SetMode(AUTOMATIC);
  pid.SetOutputLimits(-255, 255); // PWM range for motors
}

void loop() {
  input = getTiltAngle();  // Read current tilt angle
  pid.Compute();           // Calculate PID output
  driveMotors(output);     // Move motors accordingly
  delay(10);               // Short delay
}

float getTiltAngle() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Correct angle for MPU mounted flat (XY plane)
  float angle = atan2(-ax, az) * 180 / PI;
  return angle;
}

void driveMotors(double motorSpeed) {
  int pwm = abs(motorSpeed);
  pwm = constrain(pwm, 0, 255);

  if (motorSpeed > 0) {
    // Move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    // Move backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  analogWrite(ENA, pwm);
  analogWrite(ENB, pwm);
}
