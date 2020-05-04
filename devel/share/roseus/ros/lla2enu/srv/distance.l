;; Auto-generated. Do not edit!


(when (boundp 'lla2enu::distance)
  (if (not (find-package "LLA2ENU"))
    (make-package "LLA2ENU"))
  (shadow 'distance (find-package "LLA2ENU")))
(unless (find-package "LLA2ENU::DISTANCE")
  (make-package "LLA2ENU::DISTANCE"))
(unless (find-package "LLA2ENU::DISTANCEREQUEST")
  (make-package "LLA2ENU::DISTANCEREQUEST"))
(unless (find-package "LLA2ENU::DISTANCERESPONSE")
  (make-package "LLA2ENU::DISTANCERESPONSE"))

(in-package "ROS")





(defclass lla2enu::distanceRequest
  :super ros::object
  :slots (_xEastFront _yNorthFront _zUpFront _xEastObs _yNorthObs _zUpObs ))

(defmethod lla2enu::distanceRequest
  (:init
   (&key
    ((:xEastFront __xEastFront) 0.0)
    ((:yNorthFront __yNorthFront) 0.0)
    ((:zUpFront __zUpFront) 0.0)
    ((:xEastObs __xEastObs) 0.0)
    ((:yNorthObs __yNorthObs) 0.0)
    ((:zUpObs __zUpObs) 0.0)
    )
   (send-super :init)
   (setq _xEastFront (float __xEastFront))
   (setq _yNorthFront (float __yNorthFront))
   (setq _zUpFront (float __zUpFront))
   (setq _xEastObs (float __xEastObs))
   (setq _yNorthObs (float __yNorthObs))
   (setq _zUpObs (float __zUpObs))
   self)
  (:xEastFront
   (&optional __xEastFront)
   (if __xEastFront (setq _xEastFront __xEastFront)) _xEastFront)
  (:yNorthFront
   (&optional __yNorthFront)
   (if __yNorthFront (setq _yNorthFront __yNorthFront)) _yNorthFront)
  (:zUpFront
   (&optional __zUpFront)
   (if __zUpFront (setq _zUpFront __zUpFront)) _zUpFront)
  (:xEastObs
   (&optional __xEastObs)
   (if __xEastObs (setq _xEastObs __xEastObs)) _xEastObs)
  (:yNorthObs
   (&optional __yNorthObs)
   (if __yNorthObs (setq _yNorthObs __yNorthObs)) _yNorthObs)
  (:zUpObs
   (&optional __zUpObs)
   (if __zUpObs (setq _zUpObs __zUpObs)) _zUpObs)
  (:serialization-length
   ()
   (+
    ;; float64 _xEastFront
    8
    ;; float64 _yNorthFront
    8
    ;; float64 _zUpFront
    8
    ;; float64 _xEastObs
    8
    ;; float64 _yNorthObs
    8
    ;; float64 _zUpObs
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _xEastFront
       (sys::poke _xEastFront (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yNorthFront
       (sys::poke _yNorthFront (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zUpFront
       (sys::poke _zUpFront (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _xEastObs
       (sys::poke _xEastObs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yNorthObs
       (sys::poke _yNorthObs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _zUpObs
       (sys::poke _zUpObs (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _xEastFront
     (setq _xEastFront (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yNorthFront
     (setq _yNorthFront (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zUpFront
     (setq _zUpFront (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _xEastObs
     (setq _xEastObs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yNorthObs
     (setq _yNorthObs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _zUpObs
     (setq _zUpObs (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass lla2enu::distanceResponse
  :super ros::object
  :slots (_distance ))

(defmethod lla2enu::distanceResponse
  (:init
   (&key
    ((:distance __distance) 0.0)
    )
   (send-super :init)
   (setq _distance (float __distance))
   self)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:serialization-length
   ()
   (+
    ;; float64 _distance
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _distance
     (setq _distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass lla2enu::distance
  :super ros::object
  :slots ())

(setf (get lla2enu::distance :md5sum-) "7cbb544062a87ec579943aaefdb83692")
(setf (get lla2enu::distance :datatype-) "lla2enu/distance")
(setf (get lla2enu::distance :request) lla2enu::distanceRequest)
(setf (get lla2enu::distance :response) lla2enu::distanceResponse)

(defmethod lla2enu::distanceRequest
  (:response () (instance lla2enu::distanceResponse :init)))

(setf (get lla2enu::distanceRequest :md5sum-) "7cbb544062a87ec579943aaefdb83692")
(setf (get lla2enu::distanceRequest :datatype-) "lla2enu/distanceRequest")
(setf (get lla2enu::distanceRequest :definition-)
      "float64 xEastFront
float64 yNorthFront
float64 zUpFront
float64 xEastObs
float64 yNorthObs
float64 zUpObs
---
float64 distance

")

(setf (get lla2enu::distanceResponse :md5sum-) "7cbb544062a87ec579943aaefdb83692")
(setf (get lla2enu::distanceResponse :datatype-) "lla2enu/distanceResponse")
(setf (get lla2enu::distanceResponse :definition-)
      "float64 xEastFront
float64 yNorthFront
float64 zUpFront
float64 xEastObs
float64 yNorthObs
float64 zUpObs
---
float64 distance

")



(provide :lla2enu/distance "7cbb544062a87ec579943aaefdb83692")


