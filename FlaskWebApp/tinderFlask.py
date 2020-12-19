from flask import Flask
from flask import render_template, request
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URL'] = 'sqlite:////tmp/dev.db'

db = SQLAlchemy(app)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/')
def register():
    if(register.method == "GET"):
        return render_template('register.html')
    else:
        return 'post'
        #return request.from('username')
        