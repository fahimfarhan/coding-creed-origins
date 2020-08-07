# main.py
from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello():
    return "<h1>Hey! I'm from python flask inside docker!</h1>"

if __name__ == "__main__":
    app.run(host="0.0.0.0", debug=True, port=5000)

