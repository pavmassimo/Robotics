// Generated by gencpp from file lla2enu/distanceRequest.msg
// DO NOT EDIT!


#ifndef LLA2ENU_MESSAGE_DISTANCEREQUEST_H
#define LLA2ENU_MESSAGE_DISTANCEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace lla2enu
{
template <class ContainerAllocator>
struct distanceRequest_
{
  typedef distanceRequest_<ContainerAllocator> Type;

  distanceRequest_()
    : xEastFront(0.0)
    , yNorthFront(0.0)
    , zUpFront(0.0)
    , xEastObs(0.0)
    , yNorthObs(0.0)
    , zUpObs(0.0)  {
    }
  distanceRequest_(const ContainerAllocator& _alloc)
    : xEastFront(0.0)
    , yNorthFront(0.0)
    , zUpFront(0.0)
    , xEastObs(0.0)
    , yNorthObs(0.0)
    , zUpObs(0.0)  {
  (void)_alloc;
    }



   typedef double _xEastFront_type;
  _xEastFront_type xEastFront;

   typedef double _yNorthFront_type;
  _yNorthFront_type yNorthFront;

   typedef double _zUpFront_type;
  _zUpFront_type zUpFront;

   typedef double _xEastObs_type;
  _xEastObs_type xEastObs;

   typedef double _yNorthObs_type;
  _yNorthObs_type yNorthObs;

   typedef double _zUpObs_type;
  _zUpObs_type zUpObs;





  typedef boost::shared_ptr< ::lla2enu::distanceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lla2enu::distanceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct distanceRequest_

typedef ::lla2enu::distanceRequest_<std::allocator<void> > distanceRequest;

typedef boost::shared_ptr< ::lla2enu::distanceRequest > distanceRequestPtr;
typedef boost::shared_ptr< ::lla2enu::distanceRequest const> distanceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lla2enu::distanceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lla2enu::distanceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::lla2enu::distanceRequest_<ContainerAllocator1> & lhs, const ::lla2enu::distanceRequest_<ContainerAllocator2> & rhs)
{
  return lhs.xEastFront == rhs.xEastFront &&
    lhs.yNorthFront == rhs.yNorthFront &&
    lhs.zUpFront == rhs.zUpFront &&
    lhs.xEastObs == rhs.xEastObs &&
    lhs.yNorthObs == rhs.yNorthObs &&
    lhs.zUpObs == rhs.zUpObs;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::lla2enu::distanceRequest_<ContainerAllocator1> & lhs, const ::lla2enu::distanceRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace lla2enu

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::lla2enu::distanceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lla2enu::distanceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lla2enu::distanceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lla2enu::distanceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lla2enu::distanceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lla2enu::distanceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lla2enu::distanceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b956848bac18ba35585ac942e294d533";
  }

  static const char* value(const ::lla2enu::distanceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb956848bac18ba35ULL;
  static const uint64_t static_value2 = 0x585ac942e294d533ULL;
};

template<class ContainerAllocator>
struct DataType< ::lla2enu::distanceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lla2enu/distanceRequest";
  }

  static const char* value(const ::lla2enu::distanceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lla2enu::distanceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 xEastFront\n"
"float64 yNorthFront\n"
"float64 zUpFront\n"
"float64 xEastObs\n"
"float64 yNorthObs\n"
"float64 zUpObs\n"
;
  }

  static const char* value(const ::lla2enu::distanceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lla2enu::distanceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.xEastFront);
      stream.next(m.yNorthFront);
      stream.next(m.zUpFront);
      stream.next(m.xEastObs);
      stream.next(m.yNorthObs);
      stream.next(m.zUpObs);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct distanceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lla2enu::distanceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lla2enu::distanceRequest_<ContainerAllocator>& v)
  {
    s << indent << "xEastFront: ";
    Printer<double>::stream(s, indent + "  ", v.xEastFront);
    s << indent << "yNorthFront: ";
    Printer<double>::stream(s, indent + "  ", v.yNorthFront);
    s << indent << "zUpFront: ";
    Printer<double>::stream(s, indent + "  ", v.zUpFront);
    s << indent << "xEastObs: ";
    Printer<double>::stream(s, indent + "  ", v.xEastObs);
    s << indent << "yNorthObs: ";
    Printer<double>::stream(s, indent + "  ", v.yNorthObs);
    s << indent << "zUpObs: ";
    Printer<double>::stream(s, indent + "  ", v.zUpObs);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LLA2ENU_MESSAGE_DISTANCEREQUEST_H
