# @HACK 2025: Do NOT mov

> Authored by [Hugo](https://github.com/hkerma).

- **Category**: `RE`
- **Value**: `350 points`
- **Tags**: `http`

> Dr. Dexter is kind of superstitious person.
> He really gets uncomfortable around any kind of x86-64 "mov" instruction...
> 
> Can you write a program for Dr. Dexter that computes the sum of any three positive integers between 0 and 100,000?
> 
> Make sure not to use ANY "mov" instruction anywhere, or he'll know it.
> 
> ...
> 
> What do you mean "That's stupid, I am going home"?? Uh, fine ... you're allowed to use at most 4 "mov"!
> 
> ## DETAILS
> - Your program will be executed inside an x86-64 Linux environment with `glibc 2.39`.
> - The expected format of the output is "`Sum: XXXXXXX`" with XXX the sum of three random positive integers passed in `argv`.
> - The "no mov" restriction applies to any instruction in the `main` function, as well as any function called by `main`, except the `printf`, `atoi`/`atol`/`atoll` and `exit` functions of `glibc`.
> - Syscalls are restricted, except those in above-mentioned functions.
> 

## Access a dockerized instance

Run challenge container using docker compose
```
docker compose up -d
```
Open below URL on your browser
```
http://localhost:52032/
```
<details>
<summary>
How to stop/restart challenge?
</summary>

To stop the challenge run
```
docker compose stop
```
To restart the challenge run
```
docker compose restart
```

</details>


## Reveal Flag

Did you try solving this challenge?
<details>
<summary>
Yes
</summary>

Did you **REALLY** try solving this challenge?

<details>
<summary>
Yes, I promise!
</summary>

Flag: `ATHACKCTF{IDoNOTLikeToMovItMovIt}`

</details>
</details>


---

## About @HACK
[@HACK](https://athackctf.com/) is an annual CTF (Capture The Flag) competition hosted by [HEXPLOIT ALLIANCE](https://hexploit-alliance.com/) and [TECHNATION](https://technationcanada.ca/) at Concordia University in Montreal, Canada.

---
[Check more challenges from @HACK 2025](https://github.com/athack-ctf/AtHackCTF-2025-Challenges).