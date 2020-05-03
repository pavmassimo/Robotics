// Auto-generated. Do not edit!

// (in-package lla2enu.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class custom_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.status_flag = null;
      this.distance = null;
    }
    else {
      if (initObj.hasOwnProperty('status_flag')) {
        this.status_flag = initObj.status_flag
      }
      else {
        this.status_flag = '';
      }
      if (initObj.hasOwnProperty('distance')) {
        this.distance = initObj.distance
      }
      else {
        this.distance = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type custom_msg
    // Serialize message field [status_flag]
    bufferOffset = _serializer.string(obj.status_flag, buffer, bufferOffset);
    // Serialize message field [distance]
    bufferOffset = _serializer.float64(obj.distance, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type custom_msg
    let len;
    let data = new custom_msg(null);
    // Deserialize message field [status_flag]
    data.status_flag = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [distance]
    data.distance = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.status_flag.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lla2enu/custom_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2d02895aa4044caf8486e06a34e84ca5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string status_flag
    float64 distance
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new custom_msg(null);
    if (msg.status_flag !== undefined) {
      resolved.status_flag = msg.status_flag;
    }
    else {
      resolved.status_flag = ''
    }

    if (msg.distance !== undefined) {
      resolved.distance = msg.distance;
    }
    else {
      resolved.distance = 0.0
    }

    return resolved;
    }
};

module.exports = custom_msg;
