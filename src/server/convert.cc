#include <string>

#include "../proto/OC.pb.h"
#include "convert.h"

using namespace std;

OC::Object* MADS_gRPC_converter::ObjectToProto(const ObjectCube::Object* in, OC::Object* out)
{
  OC::Object* reply;
  if (out == NULL)
    reply = new OC::Object();
  else
    reply = out;

  reply->set_id(in->getId());
  reply->set_name(in->getName());
  reply->set_thumbnail(in->getThumbnail());
  reply->set_filetype(in->getFileType());
  return reply;
}

OC::TagSet* MADS_gRPC_converter::TagSetToProto(const ObjectCube::TagSet* in, OC::TagSet* out)
{
  OC::TagSet* reply;
  if (out == NULL)
    reply = new OC::TagSet();
  else
    reply = out;

  reply->set_id(in->getId());
  reply->set_name(in->getName());
  reply->set_description(in->getDescription());
  reply->set_type(in->typeAsString());
  reply->set_accessid(in->getAccessId());
  return reply;
}

OC::Tag* MADS_gRPC_converter::TagToProto(const ObjectCube::Tag* in, OC::Tag* out)
{
  OC::Tag* reply;

  if (out == NULL)
    reply = new OC::Tag();
  else
    reply = out;

  reply->set_id(in->getId());
  reply->set_tagsetid(in->getTagSetId());
  reply->set_typeid_(in->getTypeId());
  reply->set_name(in->valueAsString());
  return reply;
}

