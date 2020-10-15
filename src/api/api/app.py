import sys
sys.path.insert(0, "../../../build/src/wrapper/")

import wrapper
from flask import Flask, jsonify

hub = wrapper.Hub.getHub()

app = Flask(__name__)


@app.route("/tagsets")
def get_tagsets():
    res = list(map(lambda x: {
        "id": x.id,
        "name": x.name,
        "type": x.typeAsString(),
        "type_id": x.typeId,
    }, [t for t in hub.getTagSets()]))
    return jsonify(res)

if __name__ == "__main__":
    app.run(host='0.0.0.0')