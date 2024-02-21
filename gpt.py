import http.client
import json
import sys

def gptReq(prompt):
    apiKey = "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"
    headers = {
        "Content-type": "application/json",
        "Authorization": f"Bearer {apiKey}"
    }
    
    data = {
        "messages":[
            {
                "role": "system",
                "content": prompt
            }
        ],
        "max_tokens":100, 
        "model": "gpt-4-0613"
    }
    data = json.dumps(data)
    
    conn = http.client.HTTPSConnection("api.openai.com")
    conn.request("POST","/v1/chat/completions", body=data, headers=headers)
    resp = conn.getresponse()
    
    if resp.status ==200:
        decodedResp = json.loads(resp.read().decode())
        return decodedResp["choices"][0]["message"]["content"].strip()
    else:
        decodedResp = json.loads(resp.read().decode())
        print(decodedResp)
        return f"Error: Request failed with status {resp.status} - {resp.reason}"
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python gpt.py 'Write a prompt.'")
    else:
        inputTxt = sys.argv[1]
        prompt = ""
        if inputTxt.lower() == "english":
            prompt = input("Enter your english text : ")
            prompt = "Translate the following english text to morse code : " + prompt
        elif inputTxt.lower() == "morse":
            prompt = input("Enter your morse code : ")
            prompt = "Translate the following morse code to english text : " + prompt
        outputTxt = gptReq(prompt)
        print(outputTxt)