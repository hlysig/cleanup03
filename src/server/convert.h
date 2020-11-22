#include <string>
#include <grpcpp/grpcpp.h>
#include "OC.pb.h"
#include "../core/Hub.h"
#include "../core/LayerShared/TagCommon.h"
#include "../core/Tag/Tag.h"

using namespace std;

/*
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

    void print() {
      std::cout << "Tag("
		<< id << ", " << tagSetId << ", " << typeId << ", " << name
		<< ");" << std::endl;
    }
  };
}
*/

class convert {

public:
  static OC::Tag *TagToProto(const ObjectCube::Tag *t);

};
