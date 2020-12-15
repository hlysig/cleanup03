#include <string>

#include "../proto/OC.pb.h"
#include "convert.h"

using namespace std;

OC::Tag *convert::TagToProto(const ObjectCube::Tag *t)
{
  OC::Tag *reply = new OC::Tag();
  reply->set_id(t->getId());
  reply->set_tagsetid(t->getTagSetId());
  reply->set_typeid_(t->getTypeId());
  //std::cout << "Tag name: " << t->getName() << std::endl;
  return reply;
}
