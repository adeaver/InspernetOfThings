import facebook, sys
from pattern.en import sentiment

token = "your_access_token"
graph = facebook.GraphAPI(access_token=token)

post_data = graph.get_connections(id="some_id_here", connection_name="posts")["data"]

index = int(sys.argv[1]) if len(sys.argv) > 1 else 0
index = index % len(post_data)

while "message" not in post_data[index]:
    index += 1
    index = index % len(post_data)

status = post_data[index % len(post_data)]["message"]
sent = sentiment(status)[0]
print status

f = open("sentiment.txt", "w")
f.write(str(sent))
f.close()