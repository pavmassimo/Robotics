;; Auto-generated. Do not edit!


(when (boundp 'lla2enu::custom_msg)
  (if (not (find-package "LLA2ENU"))
    (make-package "LLA2ENU"))
  (shadow 'custom_msg (find-package "LLA2ENU")))
(unless (find-package "LLA2ENU::CUSTOM_MSG")
  (make-package "LLA2ENU::CUSTOM_MSG"))

(in-package "ROS")
;;//! \htmlinclude custom_msg.msg.html


(defclass lla2enu::custom_msg
  :super ros::object
  :slots (_status_flag _distance ))

(defmethod lla2enu::custom_msg
  (:init
   (&key
    ((:status_flag __status_flag) "")
    ((:distance __distance) 0.0)
    )
   (send-super :init)
   (setq _status_flag (string __status_flag))
   (setq _distance (float __distance))
   self)
  (:status_flag
   (&optional __status_flag)
   (if __status_flag (setq _status_flag __status_flag)) _status_flag)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:serialization-length
   ()
   (+
    ;; string _status_flag
    4 (length _status_flag)
    ;; float64 _distance
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _status_flag
       (write-long (length _status_flag) s) (princ _status_flag s)
     ;; float64 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _status_flag
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _status_flag (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float64 _distance
     (setq _distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get lla2enu::custom_msg :md5sum-) "2d02895aa4044caf8486e06a34e84ca5")
(setf (get lla2enu::custom_msg :datatype-) "lla2enu/custom_msg")
(setf (get lla2enu::custom_msg :definition-)
      "string status_flag
float64 distance

")



(provide :lla2enu/custom_msg "2d02895aa4044caf8486e06a34e84ca5")


