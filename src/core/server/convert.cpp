#include <string>

#include "../proto/OC.pb.h"
#include "convert.h"

using namespace std;

OC::GetTagResponse *convert::TagToProto(Tag *t)
{
  OC::Tag *prototag = new OC::Tag();
  prototag->set_id(t->getId());
  prototag->set_tagsetid(t->getTagSetId());
  prototag->set_typeid_(t->getTypeId());
  prototag->set_name(t->getName());

  OC::GetTagResponse *reply = new OC::GetTagResponse();
  reply->set_allocated_tag(prototag);
  return reply;
}
