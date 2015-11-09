import facebook, sys
from pattern.en import sentiment

token = "your_access_token_here"
graph = facebook.GraphAPI(access_token=token)

post_data = graph.get_connections(id="some_id_here", connection_name="posts")["data"]

index = sys.argv[0] if len(sys.argv) > 0 else 0
index = index

while "message" not in post_data[index % len(post_data)]:
    index += 1

status = post_data[index % len(post_data)]["message"]
sent = sentiment(status)[0]

f = open("sentiment.txt", "w")
f.write(sent)
f.close()