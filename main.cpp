// use 8_4_Acc_Gyro
/*include "mbed.h"
#include "accelerometer.h"
#include "gyro.h"

AnalogOut Aout(PA_4);
InterruptIn btnRecord(BUTTON1);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread thread;
Accelerometer acc;
Gyro gyro;
Timer t;
double Accel[3]={0};
double Gyro[3]={0};
double  accAngleX=0;
double  accAngleY=0;
double elapsedTime=0;
double roll, pitch, yaw;
double gyroAngleX=0;
double gyroAngleY=0;
int counter=0;
int idR[32] = {0};
int indexR = 0;
double acc_accel[3];
double avg_accel[3];
double gy_gyro[3];
double avg_gyro[3];
int num_sample = 10;


void record(void) {
  
  for (int i = 0; i <10; i++){
    acc.GetAcceleromterSensor(acc_accel);
    acc.GetAcceleromterCalibratedData(acc_accel);

    Accel[0] += acc_accel[0];
    Accel[1] += acc_accel[1];
    Accel[2] += acc_accel[2];

    gyro.GetGyroSensor(gy_gyro);
    gyro.GetGyroCalibratedData(gy_gyro);

    Gyro[0] += gy_gyro[0];
    Gyro[1] += gy_gyro[1];
    Gyro[2] += gy_gyro[2];
  }

  for (int i = 0; i < 3; i++) {
    avg_accel[i] = Accel[i] / num_sample;
    avg_gyro[i]  = Gyro[i] / num_sample;
  }
    
    // Calculating Roll and Pitch from the accelerometer data
    accAngleX = (atan(avg_accel[1] / sqrt(avg_accel[0]*avg_accel[1] + avg_accel[2]*avg_accel[2])) * 180 / SENSOR_PI_DOUBLE);
    accAngleY = (atan(-1 * avg_accel[1] / sqrt(avg_accel[1]*avg_accel[1] + avg_accel[2]*avg_accel[2])) * 180 / SENSOR_PI_DOUBLE);
    
    elapsedTime=0.15; //100ms by thread sleep time
    // Currently the raw values are in degrees per seconds, deg/s, so we need to multiply by sendonds (s) to get the angle in degrees
    gyroAngleX = gyroAngleX + avg_gyro[0] * elapsedTime; // deg/s * s = deg
    gyroAngleY = gyroAngleY + avg_gyro[1] * elapsedTime;
  
    roll = accAngleX;
    pitch = accAngleY;
    yaw =  yaw + avg_gyro[2] * elapsedTime;
    printf("%f/%f/%f\n", roll, pitch, yaw);
}

void startRecord(void) {
  //printf("---start---\n");
  idR[indexR++] = queue.call_every(100ms, record);
  indexR = indexR % 32;
}

void stopRecord(void) {
  //printf("---stop---\n");
  for (auto &i : idR)
    queue.cancel(i);
}

int main() {
  thread.start(callback(&queue, &EventQueue::dispatch_forever));
  btnRecord.fall(queue.event(startRecord));
  btnRecord.rise(queue.event(stopRecord));
}
*/