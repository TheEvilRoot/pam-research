import flask

app = flask.Flask(__name__)

@app.route('/<endp>', methods=['GET', 'HEAD'])
def auth(endp):
    print(endp)
    print(flask.request.args)
    if endp != 'auth':
        print('bypassing other methods')
        return ('', 200)
    user = flask.request.args['u']
    print('authorize' , user ,'on', endp)
    v = input()
    if v == 'yes':
        return ('', 200)
    return ('', 500)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=3333)
