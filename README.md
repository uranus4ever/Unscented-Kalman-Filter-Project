# **Object Tracking with Unscented Kalman Filter**

### Objective
Utilize sensor data from both LIDAR and RADAR measurements for object (e.g. pedestrian, vehicles, bicycle, or other moving objects) tracking with Unscented Kalman Filter.

![ukf][img2]

## Instruction
### 1. Dependencies & Environment

* cmake >= 3.5
* make >= 4.1
* gcc/g++ >= 5.4
* Eigen library

### 2. My project files

* `CMakeLists.txt` is the cmake file.
* `data` folder contains test lidar and radar measurements.
* `Docs` folder contains docments which describe the data.
* `src` folder contains the source code.
 * `main.cpp` - reads in data, calls a function to run the Kalman filter, calls a function to calculate RMSE.
 * `ukf.cpp` - initializes the filter, calls the predict function, calls the update function.
 * `tools.cpp` - a function to calculate RMSE and the Jacobian matrix.

### 3. How to run the code

1. Clone this repo.
2. Download the Udacity Term-2 [simulator](https://github.com/udacity/self-driving-car-sim/releases/tag/v1.0).
3. Make a build directory: `mkdir build && cd build`
4. Compile: `cmake .. && make` 
   * On windows, you may need to run: `cmake .. -G "Unix Makefiles" && make`
5. Run the command: `./UnscentedKF`.
6. Run the simulator.


## Result

Threshold for EKF: RMSE <= [0.11, 0.11, 0.52, 0.52] 
**Threshold for UKF: RMSE <= [0.09, 0.10, 0.40, 0.30]**

RMSE Accuracy (Both with dataset 1): 

|      State  |  UKF   |    EKF    |   
|:-----------:|:------:|:---------:|
|      px     | 0.0762 |  0.0973   | 
|      py     | 0.0841 |  0.0855   |   
|      vx     | 0.3232 |  0.4513   |  
|      vy     | 0.2979 |  0.4399   | 


![Lidar and Radar][img4]

_Both Lidar and Radar_

_Note:_
Red Circle - LIDAR measurements
Blue Circle - RADAR measurements
Green triangle - Estimated location


|      State  |  Lidar and Radar   |    only Lidar  |   only Radar   |
|:-----------:|:------------------:|:--------------:|:--------------:|
|      px     |    0.0762          |    0.1760      |    0.2273      |
|      py     |    0.0841          |    0.1488      |    0.2973      |  
|      vx     |    0.3232          |    0.5553      |    0.5146      | 
|      vy     |    0.2979          |    0.2973      |    0.3964      |


![Lidar only][img5]

_Lidar Only_

![Radar only][img6]

_Radar Only_

**Discussion**:

* From table 1, we can see UKF performs better than EKF in all estimations.
* From table 2, we can see fusion with both lidar and radar measurements improves tracking a lot, especially for position estimation.

## Knowledge Background

### 1. Motion Model: CTRV model

![CTRV mdoel][img1]

### 2. Unsented Kalman Filter Roadmap

![roadmap][img3]

### 3. Comparison between EKF and UKF

All Kalman filters have three steps: Initialization --> Prediction --> Update. A standard **Kalman Filter**(KF) can only deal with linear equations. Both **[Extended Kalman Filter](https://github.com/uranus4ever/Extended-Kalman-Filter-Project)**(EKF) and **Unscented Kalman Filter**(UKF) is able to use non-linear equations; the difference is: EKF uses Jacobian matrix to linearize non-liear functions, while UKF takes representative points from a Gaussian distribution. 


[//]: # (Image References)
[img1]: ./extra/ctrv.jpg
[img2]: ./extra/ukf.jpg
[img3]: ./extra/ukf_roadmap.jpg
[img4]: ./extra/UKF-L-R.PNG
[img5]: ./extra/UKF-L.PNG
[img6]: ./extra/UKF-R.PNG
