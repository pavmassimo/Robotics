// Auto-generated. Do not edit!

// (in-package lla2enu.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class distanceRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.xEastFront = null;
      this.yNorthFront = null;
      this.zUpFront = null;
      this.xEastObs = null;
      this.yNorthObs = null;
      this.zUpObs = null;
    }
    else {
      if (initObj.hasOwnProperty('xEastFront')) {
        this.xEastFront = initObj.xEastFront
      }
      else {
        this.xEastFront = 0.0;
      }
      if (initObj.hasOwnProperty('yNorthFront')) {
        this.yNorthFront = initObj.yNorthFront
      }
      else {
        this.yNorthFront = 0.0;
      }
      if (initObj.hasOwnProperty('zUpFront')) {
        this.zUpFront = initObj.zUpFront
      }
      else {
        this.zUpFront = 0.0;
      }
      if (initObj.hasOwnProperty('xEastObs')) {
        this.xEastObs = initObj.xEastObs
      }
      else {
        this.xEastObs = 0.0;
      }
      if (initObj.hasOwnProperty('yNorthObs')) {
        this.yNorthObs = initObj.yNorthObs
      }
      else {
        this.yNorthObs = 0.0;
      }
      if (initObj.hasOwnProperty('zUpObs')) {
        this.zUpObs = initObj.zUpObs
      }
      else {
        this.zUpObs = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type distanceRequest
    // Serialize message field [xEastFront]
    bufferOffset = _serializer.float64(obj.xEastFront, buffer, bufferOffset);
    // Serialize message field [yNorthFront]
    bufferOffset = _serializer.float64(obj.yNorthFront, buffer, bufferOffset);
    // Serialize message field [zUpFront]
    bufferOffset = _serializer.float64(obj.zUpFront, buffer, bufferOffset);
    // Serialize message field [xEastObs]
    bufferOffset = _serializer.float64(obj.xEastObs, buffer, bufferOffset);
    // Serialize message field [yNorthObs]
    bufferOffset = _serializer.float64(obj.yNorthObs, buffer, bufferOffset);
    // Serialize message field [zUpObs]
    bufferOffset = _serializer.float64(obj.zUpObs, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type distanceRequest
    let len;
    let data = new distanceRequest(null);
    // Deserialize message field [xEastFront]
    data.xEastFront = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yNorthFront]
    data.yNorthFront = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [zUpFront]
    data.zUpFront = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [xEastObs]
    data.xEastObs = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yNorthObs]
    data.yNorthObs = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [zUpObs]
    data.zUpObs = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lla2enu/distanceRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b956848bac18ba35585ac942e294d533';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 xEastFront
    float64 yNorthFront
    float64 zUpFront
    float64 xEastObs
    float64 yNorthObs
    float64 zUpObs
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new distanceRequest(null);
    if (msg.xEastFront !== undefined) {
      resolved.xEastFront = msg.xEastFront;
    }
    else {
      resolved.xEastFront = 0.0
    }

    if (msg.yNorthFront !== undefined) {
      resolved.yNorthFront = msg.yNorthFront;
    }
    else {
      resolved.yNorthFront = 0.0
    }

    if (msg.zUpFront !== undefined) {
      resolved.zUpFront = msg.zUpFront;
    }
    else {
      resolved.zUpFront = 0.0
    }

    if (msg.xEastObs !== undefined) {
      resolved.xEastObs = msg.xEastObs;
    }
    else {
      resolved.xEastObs = 0.0
    }

    if (msg.yNorthObs !== undefined) {
      resolved.yNorthObs = msg.yNorthObs;
    }
    else {
      resolved.yNorthObs = 0.0
    }

    if (msg.zUpObs !== undefined) {
      resolved.zUpObs = msg.zUpObs;
    }
    else {
      resolved.zUpObs = 0.0
    }

    return resolved;
    }
};

class distanceResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.distance = null;
    }
    else {
      if (initObj.hasOwnProperty('distance')) {
        this.distance = initObj.distance
      }
      else {
        this.distance = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type distanceResponse
    // Serialize message field [distance]
    bufferOffset = _serializer.float64(obj.distance, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type distanceResponse
    let len;
    let data = new distanceResponse(null);
    // Deserialize message field [distance]
    data.distance = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'lla2enu/distanceResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'acff7fda0c683c872875f5c4b069f124';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 distance
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new distanceResponse(null);
    if (msg.distance !== undefined) {
      resolved.distance = msg.distance;
    }
    else {
      resolved.distance = 0.0
    }

    return resolved;
    }
};

module.exports = {
  Request: distanceRequest,
  Response: distanceResponse,
  md5sum() { return '7cbb544062a87ec579943aaefdb83692'; },
  datatype() { return 'lla2enu/distance'; }
};
