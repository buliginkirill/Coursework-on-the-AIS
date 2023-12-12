import base64
import time

from requests import get, post

time.sleep(10)

url_user = 'http://user:8080'
url_wall = 'http://wall:8080'
url_chat = 'http://chat:8080'

# вызовы user
call = url_user+'/auth'
print(call)
auth_token = 'Basic '+base64.encodebytes(b'sidorov:sidorov').decode('utf-8')[:-1]
res = get(call, params={'login': 'user', 'password': 'password'}, headers={'Authorization': auth_token})
print(res.text)


call = url_user+'/auth'
print(call)
auth_token = 'Basic '+base64.encodebytes(b'petrov:petrov').decode('utf-8')[:-1]
res = get(call, params={'login': 'user', 'password': 'password'}, headers={'Authorization': auth_token})
print(res.text)

call = url_user+'/auth'
print(call)
auth_token = 'Basic '+base64.encodebytes(b'ivanov:ivanov').decode('utf-8')[:-1]
res = get(call, params={'login': 'user', 'password': 'password'}, headers={'Authorization': auth_token})
print(res.text)

call = url_user+'/search'
print(call)
res = get(call, params={'first_name': 'И', 'last_name': 'И'})
print(res.text)

call = url_user+'/search'
print(call)
res = get(call, params={'first_name': 'П', 'last_name': 'П'})
print(res.text)

call = url_user+'/search'
print(call)
res = get(call, params={'first_name': 'С', 'last_name': 'С'})
print(res.text)

call = url_user+'/user'
print(call)
res = get(call, params={'id': 1})
print(res.text)

call = url_user+'/user'
print(call)
res = get(call, params={'id': 2})
print(res.text)

call = url_user+'/user'
print(call)
res = get(call, params={'id': 3})
print(res.text)

call = url_user+'/user'
print(call)
res = post(call, data={
 "first_name":'test',
 "last_name":'test',
 "email":'test@test.test',
 "title":'test',
 "login":'test',
 "password":'test'
})
print(res.text)

# вызовы wall
call = url_wall+'/wall'
print(call)
res = get(call, params={'user_id': 1})
print(res.text)


call = url_wall+'/wall'
print(call)
res = post(call, data={
    "user_id":1,
    "message":'test_message'
})
print(res.text)

# вызовы chat
call = url_chat+'/chat'
print(call)
res = get(call, params={'user_id': 1})
print(res.text)


call = url_chat+'/chat'
print(call)
res = post(call, data={
    "user_id":1,
    "message":'test_message'
})
print(res.text)


