
import re
import json

input_str ="tqmrajq ya gowopxyoap, fxog vcasqffac ycqmxtpql, tka kxg fqxyqg kqcfqms op x topiqg xcjrkxoc op scapy as ykq socq. jl pxjq of vcasqffac ycqmxtpql. lae jxl pay kxwq fqqp jq zqsacq. o sopg ykxy gqfrqpgopi yaa asyqp opya ykq kefymq xpg zefymq as ykq jxop frkaam rmaegf jl oppqc qlq. pazagl fxog xplykopi ya ykof qbycxacgopxcl vcapaeprqjqpy. vcasqffac ycqmxtpql gqmorxyqml cqxccxpiqg kqc fkxtm xpg rapyopeqg, fa lae kxwq rkafqp ya fyegl gowopxyoap, ykq jafy gossoremy as xmm jxiorxm xcyf. o jefy"



encrypted_freq = {}
for i in range(0,26):
    encrypted_freq[chr(i+ord('a'))]=0

for i in input_str:
    if i not in [" ",",","."]:
        encrypted_freq[i] += 1
    

encrypted_freq = sorted(encrypted_freq.items(),key=lambda x:x[1],reverse=True)
encrypted_freq = dict(encrypted_freq)

original_freq = json.load(open("./frequency.json","r"))


original_freq = dict(sorted(original_freq.items(),key=lambda x:x[1],reverse=True))

mapping = {}

encrypted_freq_keys = list(encrypted_freq.keys())
original_freq_keys = list(original_freq.keys())

for i in range(0,26):
    mapping[encrypted_freq_keys[i]] = original_freq_keys[i]

mapping[' '] = ' '

mapping = {
  "q": "e",
  "a": "s",
  "p": "o",
  "y": "a",
  "x": "i.",
  "o": "n",
  "c": "w",
  "f": "h",
  "g": "r",
  "k": "d",
  "m": "l",
  "l": "u",
  "s": "t",
  "j": "m",
  "r": "g",
  "e": "c",
  "t": "f",
  "i": "y",
  "v": "b",
  "w": "p",
  "z": "k",
  "b": "v",
  "d": "j",
  "h": "x",
  "n": "q",
  "u": "z",
  " ": " "
}


mapping["."] = "."
mapping[","] = ","

decrypted_text = ""
for i in input_str:
    decrypted_text += mapping[i]

print(decrypted_text)

