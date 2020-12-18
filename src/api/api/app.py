from flask import Flask, jsonify
from client import MADSClient

app = Flask(__name__)
client = MADSClient()


@app.route('/tagset')
def get_tagsets():
    resp = client.get_tagsets()
    return jsonify(resp)

@app.route('/tagset/<int:tagset_id>')
def get_tagset(tagset_id):
    resp = client.get_tagset(tagset_id)
    return jsonify(resp)

@app.route('/tag')
def get_tags():
    resp = client.get_tags()
    return jsonify(resp)

@app.route('/tag/<int:tag_id>')
def get_tag(tag_id):
    resp = client.get_tag(tag_id)
    return jsonify(resp)



if __name__ == "__main__":
    app.run(host='0.0.0.0')
