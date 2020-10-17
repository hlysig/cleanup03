from flask import Flask, jsonify
from oc import OC

app = Flask(__name__)


@app.route("/tagsets")
def get_tagsets():
    oc = OC()
    res = list(map(lambda x: {
        "id": x.id,
        "name": x.name,
        "type": x.typeAsString(),
        "type_id": x.typeId,
    }, [t for t in oc.get_hub().getTagSets()]))
    return jsonify(res)


if __name__ == "__main__":
    app.run(host='0.0.0.0')
