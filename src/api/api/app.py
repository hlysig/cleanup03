from flask import Flask, jsonify
from client import ObjectCubeClient

app = Flask(__name__)
client = ObjectCubeClient()


@app.route('/tag/<int:tag_id>')
def get_tagsets(tag_id):
    resp = client.get_tag(tag_id)
    return jsonify(resp)


if __name__ == "__main__":
    app.run(host='0.0.0.0')
