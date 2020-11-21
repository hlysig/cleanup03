#include <string>

#include "../proto/OC.pb.h"

using namespace std;

namespace ObjectCube
{
  class Tag {
  public:
    int id;
    int tagSetId;
    int typeId;
    string name;
    
    int getId() { return id; }
    int getTagSetId() { return tagSetId; }
    int getTypeId() { return typeId; }
    string getName() { return name; }

    Tag(int _id, int _tagSetId, int _typeId, string _name) {
      id = _id;
      tagSetId = _tagSetId;
      typeId = _typeId;
      name = _name;
    }
  };
}

class convert {

public:
  static OC::GetTagResponse *TagToProto(ObjectCube::Tag *t);

};
