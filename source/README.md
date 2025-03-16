# Running This challenge

Build
```
docker build -t athack-ctf/chall2025-do-not-mov:latest .
```

Run
```
docker run -d --name do-not-mov \
  -p 52032:5000 \
  athack-ctf/chall2025-do-not-mov:latest
```
