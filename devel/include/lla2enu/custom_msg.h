// Generated by gencpp from file lla2enu/custom_msg.msg
// DO NOT EDIT!


#ifndef LLA2ENU_MESSAGE_CUSTOM_MSG_H
#define LLA2ENU_MESSAGE_CUSTOM_MSG_H


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
struct custom_msg_
{
  typedef custom_msg_<ContainerAllocator> Type;

  custom_msg_()
    : status_flag()
    , distance(0.0)  {
    }
  custom_msg_(const ContainerAllocator& _alloc)
    : status_flag(_alloc)
    , distance(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_flag_type;
  _status_flag_type status_flag;

   typedef double _distance_type;
  _distance_type distance;





  typedef boost::shared_ptr< ::lla2enu::custom_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::lla2enu::custom_msg_<ContainerAllocator> const> ConstPtr;

}; // struct custom_msg_

typedef ::lla2enu::custom_msg_<std::allocator<void> > custom_msg;

typedef boost::shared_ptr< ::lla2enu::custom_msg > custom_msgPtr;
typedef boost::shared_ptr< ::lla2enu::custom_msg const> custom_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::lla2enu::custom_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::lla2enu::custom_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::lla2enu::custom_msg_<ContainerAllocator1> & lhs, const ::lla2enu::custom_msg_<ContainerAllocator2> & rhs)
{
  return lhs.status_flag == rhs.status_flag &&
    lhs.distance == rhs.distance;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::lla2enu::custom_msg_<ContainerAllocator1> & lhs, const ::lla2enu::custom_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace lla2enu

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::lla2enu::custom_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::lla2enu::custom_msg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lla2enu::custom_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::lla2enu::custom_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lla2enu::custom_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::lla2enu::custom_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::lla2enu::custom_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2d02895aa4044caf8486e06a34e84ca5";
  }

  static const char* value(const ::lla2enu::custom_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2d02895aa4044cafULL;
  static const uint64_t static_value2 = 0x8486e06a34e84ca5ULL;
};

template<class ContainerAllocator>
struct DataType< ::lla2enu::custom_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "lla2enu/custom_msg";
  }

  static const char* value(const ::lla2enu::custom_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::lla2enu::custom_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string status_flag\n"
"float64 distance\n"
;
  }

  static const char* value(const ::lla2enu::custom_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::lla2enu::custom_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.status_flag);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct custom_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::lla2enu::custom_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::lla2enu::custom_msg_<ContainerAllocator>& v)
  {
    s << indent << "status_flag: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.status_flag);
    s << indent << "distance: ";
    Printer<double>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LLA2ENU_MESSAGE_CUSTOM_MSG_H