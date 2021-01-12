#include <string>

#include "../proto/MADS.pb.h"
#include "convert.h"

using namespace std;

MADS::Object* MADS_gRPC_converter::ObjectToProto(const ObjectCube::Object* in, MADS::Object* out)
{
  MADS::Object* reply;
  if (out == NULL)
    reply = new MADS::Object();
  else
    reply = out;

  reply->set_id(in->getId());
  reply->set_uri(in->getName());
  reply->set_thumbnail(in->getThumbnail());
  reply->set_filetype(in->getFileType());
  return reply;
}

MADS::TagSet* MADS_gRPC_converter::TagSetToProto(const ObjectCube::TagSet* in, MADS::TagSet* out)
{
  MADS::TagSet* reply;
  if (out == NULL)
    reply = new MADS::TagSet();
  else
    reply = out;

  reply->set_id(in->getId());
  reply->set_name(in->getName());
  reply->set_description(in->getDescription());
  reply->set_accessid(in->getAccessId());

  switch (in->getTypeId()) {
  case ObjectCube::TagSetCommon::ALPHANUMERICAL:
    reply->set_type(MADS::TagSetType::ALPHANUMERICAL);
    break;
  case ObjectCube::TagSetCommon::NUMERICAL:
    reply->set_type(MADS::TagSetType::NUMERICAL);
    break;
  case ObjectCube::TagSetCommon::DATE:
    reply->set_type(MADS::TagSetType::DATE);
    break;
  case ObjectCube::TagSetCommon::TIME:
    reply->set_type(MADS::TagSetType::TIME);
    break;
  case ObjectCube::TagSetCommon::RGB:
    reply->set_type(MADS::TagSetType::RGB);
    break;
  default:
    reply->set_type(MADS::TagSetType::TYPE_UNKNOWN);
  }

  return reply;
}

MADS::Tag* MADS_gRPC_converter::TagToProto(const ObjectCube::Tag* in, MADS::Tag* out)
{
  MADS::Tag* reply;

  if (out == NULL)
    reply = new MADS::Tag();
  else
    reply = out;

  reply->set_id(in->getId());
  reply->set_tagsetid(in->getTagSetId());
  reply->set_typeid_(in->getTypeId());

  switch (in->getTypeId()) {
  case ObjectCube::TagSetCommon::ALPHANUMERICAL:
    {
      MADS::AlphanumericalValue* value = new MADS::AlphanumericalValue();
      value->set_value(in->valueAsString());
      reply->set_allocated_alphanumerical(value);
      break;
    }
  case ObjectCube::TagSetCommon::NUMERICAL:
    {
      MADS::NumericalValue* value = new MADS::NumericalValue();
      value->set_value(in->valueAsString());
      reply->set_allocated_numerical(value);
      break;
    }
  case ObjectCube::TagSetCommon::DATE:
    {
      MADS::DateValue* value = new MADS::DateValue();
      value->set_value(in->valueAsString());
      reply->set_allocated_date(value);
      break;
    }
  case ObjectCube::TagSetCommon::TIME:
    {
      MADS::TimeValue* value = new MADS::TimeValue();
      value->set_value(in->valueAsString());
      reply->set_allocated_time(value);
      break;
    }
  case ObjectCube::TagSetCommon::RGB:
    {
      // TODO: Parse actual RGB values
      MADS::RGBValue* value = new MADS::RGBValue();
      value->set_red(34);
      value->set_green(56);
      value->set_blue(87);
      reply->set_allocated_rgb(value);
      break;
    }
  default:
    {
      MADS::AlphanumericalValue* value = new MADS::AlphanumericalValue();
      value->set_value(in->valueAsString());
      reply->set_allocated_alphanumerical(value);
      break;
    }
  }

  return reply;
}

