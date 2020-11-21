#include <string>

#include "cmake/build/OC.pb.h"
#include "convert.h"

using namespace std;

OC::Tag *convert::TagToProto(ObjectCube::Tag *t)
{
  OC::Tag *reply = new OC::Tag();
  reply->set_id(t->getId());
  reply->set_tagsetid(t->getTagSetId());
  reply->set_typeid_(t->getTypeId());
  reply->set_name(t->getName());
  return reply;
}
