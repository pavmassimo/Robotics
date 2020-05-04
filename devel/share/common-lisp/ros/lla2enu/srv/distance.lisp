; Auto-generated. Do not edit!


(cl:in-package lla2enu-srv)


;//! \htmlinclude distance-request.msg.html

(cl:defclass <distance-request> (roslisp-msg-protocol:ros-message)
  ((xEastFront
    :reader xEastFront
    :initarg :xEastFront
    :type cl:float
    :initform 0.0)
   (yNorthFront
    :reader yNorthFront
    :initarg :yNorthFront
    :type cl:float
    :initform 0.0)
   (zUpFront
    :reader zUpFront
    :initarg :zUpFront
    :type cl:float
    :initform 0.0)
   (xEastObs
    :reader xEastObs
    :initarg :xEastObs
    :type cl:float
    :initform 0.0)
   (yNorthObs
    :reader yNorthObs
    :initarg :yNorthObs
    :type cl:float
    :initform 0.0)
   (zUpObs
    :reader zUpObs
    :initarg :zUpObs
    :type cl:float
    :initform 0.0))
)

(cl:defclass distance-request (<distance-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <distance-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'distance-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lla2enu-srv:<distance-request> is deprecated: use lla2enu-srv:distance-request instead.")))

(cl:ensure-generic-function 'xEastFront-val :lambda-list '(m))
(cl:defmethod xEastFront-val ((m <distance-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lla2enu-srv:xEastFront-val is deprecated.  Use lla2enu-srv:xEastFront instead.")
  (xEastFront m))

(cl:ensure-generic-function 'yNorthFront-val :lambda-list '(m))
(cl:defmethod yNorthFront-val ((m <distance-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lla2enu-srv:yNorthFront-val is deprecated.  Use lla2enu-srv:yNorthFront instead.")
  (yNorthFront m))

(cl:ensure-generic-function 'zUpFront-val :lambda-list '(m))
(cl:defmethod zUpFront-val ((m <distance-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lla2enu-srv:zUpFront-val is deprecated.  Use lla2enu-srv:zUpFront instead.")
  (zUpFront m))

(cl:ensure-generic-function 'xEastObs-val :lambda-list '(m))
(cl:defmethod xEastObs-val ((m <distance-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lla2enu-srv:xEastObs-val is deprecated.  Use lla2enu-srv:xEastObs instead.")
  (xEastObs m))

(cl:ensure-generic-function 'yNorthObs-val :lambda-list '(m))
(cl:defmethod yNorthObs-val ((m <distance-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lla2enu-srv:yNorthObs-val is deprecated.  Use lla2enu-srv:yNorthObs instead.")
  (yNorthObs m))

(cl:ensure-generic-function 'zUpObs-val :lambda-list '(m))
(cl:defmethod zUpObs-val ((m <distance-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lla2enu-srv:zUpObs-val is deprecated.  Use lla2enu-srv:zUpObs instead.")
  (zUpObs m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <distance-request>) ostream)
  "Serializes a message object of type '<distance-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'xEastFront))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'yNorthFront))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'zUpFront))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'xEastObs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'yNorthObs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'zUpObs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <distance-request>) istream)
  "Deserializes a message object of type '<distance-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'xEastFront) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yNorthFront) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zUpFront) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'xEastObs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yNorthObs) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zUpObs) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<distance-request>)))
  "Returns string type for a service object of type '<distance-request>"
  "lla2enu/distanceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'distance-request)))
  "Returns string type for a service object of type 'distance-request"
  "lla2enu/distanceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<distance-request>)))
  "Returns md5sum for a message object of type '<distance-request>"
  "7cbb544062a87ec579943aaefdb83692")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'distance-request)))
  "Returns md5sum for a message object of type 'distance-request"
  "7cbb544062a87ec579943aaefdb83692")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<distance-request>)))
  "Returns full string definition for message of type '<distance-request>"
  (cl:format cl:nil "float64 xEastFront~%float64 yNorthFront~%float64 zUpFront~%float64 xEastObs~%float64 yNorthObs~%float64 zUpObs~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'distance-request)))
  "Returns full string definition for message of type 'distance-request"
  (cl:format cl:nil "float64 xEastFront~%float64 yNorthFront~%float64 zUpFront~%float64 xEastObs~%float64 yNorthObs~%float64 zUpObs~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <distance-request>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <distance-request>))
  "Converts a ROS message object to a list"
  (cl:list 'distance-request
    (cl:cons ':xEastFront (xEastFront msg))
    (cl:cons ':yNorthFront (yNorthFront msg))
    (cl:cons ':zUpFront (zUpFront msg))
    (cl:cons ':xEastObs (xEastObs msg))
    (cl:cons ':yNorthObs (yNorthObs msg))
    (cl:cons ':zUpObs (zUpObs msg))
))
;//! \htmlinclude distance-response.msg.html

(cl:defclass <distance-response> (roslisp-msg-protocol:ros-message)
  ((distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass distance-response (<distance-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <distance-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'distance-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name lla2enu-srv:<distance-response> is deprecated: use lla2enu-srv:distance-response instead.")))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <distance-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader lla2enu-srv:distance-val is deprecated.  Use lla2enu-srv:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <distance-response>) ostream)
  "Serializes a message object of type '<distance-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <distance-response>) istream)
  "Deserializes a message object of type '<distance-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<distance-response>)))
  "Returns string type for a service object of type '<distance-response>"
  "lla2enu/distanceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'distance-response)))
  "Returns string type for a service object of type 'distance-response"
  "lla2enu/distanceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<distance-response>)))
  "Returns md5sum for a message object of type '<distance-response>"
  "7cbb544062a87ec579943aaefdb83692")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'distance-response)))
  "Returns md5sum for a message object of type 'distance-response"
  "7cbb544062a87ec579943aaefdb83692")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<distance-response>)))
  "Returns full string definition for message of type '<distance-response>"
  (cl:format cl:nil "float64 distance~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'distance-response)))
  "Returns full string definition for message of type 'distance-response"
  (cl:format cl:nil "float64 distance~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <distance-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <distance-response>))
  "Converts a ROS message object to a list"
  (cl:list 'distance-response
    (cl:cons ':distance (distance msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'distance)))
  'distance-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'distance)))
  'distance-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'distance)))
  "Returns string type for a service object of type '<distance>"
  "lla2enu/distance")