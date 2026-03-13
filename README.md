# Fall Detection System

A fall detection and activity recognition system built with Arduino Nano 33 BLE Sense Rev 2 and Edge Impulse.

## Overview

This project uses machine learning to classify human activities into two categories:
- **Activities of Daily Living (ADL)** - Normal daily movements
- **Falls** - Sudden uncontrolled movements indicating a fall event

The system monitors acceleration data from a 3-axis accelerometer and classifies activities in real-time on the IoT device.

## Hardware

- **Microcontroller**: Arduino Nano 33 BLE Sense Rev 2
- **Sensor**: Built-in BMI270 accelerometer (3-axis)
- **Communication**: Bluetooth Low Energy (BLE)

## Machine Learning Model

- **Architecture**: 1D Convolutional Neural Network (1D CNN)
- **Input**: 3-axis accelerometer data
- **Training Dataset**: SisFall (fall detection benchmark dataset)
- **Framework**: Edge Impulse
- **Deployment**: TensorFlow Lite Micro

## Project Structure

- `src/` - Main firmware code
- `src/main.cpp` - Arduino entry point
- `src/main_functions.cpp/h` - Application logic for data collection and inference
- `src/edge-impulse-sdk/` - Edge Impulse ML SDK
- `src/tflite-model/` - Compiled TensorFlow Lite model

## Building & Uploading

This project uses PlatformIO. To build and upload:

```bash
platformio run --target upload
```

Monitor serial output:

```bash
platformio device monitor --baud 115200
```

## Features

- Real-time fall detection on-device
- Low power consumption with ARM Cortex-M4
- Fast inference using optimized TensorFlow Lite model
- Serial debugging output
