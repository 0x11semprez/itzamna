<p align="center"><img src="docs/logo.png" alt="ITZAMNA" width="600"></p>

itzamna is a system VM designed to safely execute and test critical or potentially dangerous code in CI pipelines and CTF environments.<br/>
itzamna supports its own virtual machine, written from scratch in C.<br/>
itzamna supports running untrusted binaries in an isolated sandbox, with no access to the host by default.<br/>
itzamna supports resource limits (CPU, memory, time) and a full trace of every syscall the guest makes.<br/>
itzamna ships with its own command line tool, written in Go, so the whole workflow lives in one place.<br/>
<br/>

itzamna build <br/>

```bash
cmake -B build && cmake --build build
```

itzamna workflow <br/>
itzamna is not only a VM: the `itzamna` command drives the full pipeline, from building the VM to running and inspecting your payloads, without leaving the terminal. <br/>

```bash
itzamna build              # configure & build the VM
itzamna install            # copy the binaries into your PATH (~/.local/bin)
itzamna run <file>         # execute a binary inside the VM
itzamna run --trace <file> # execute and print every syscall the guest makes
itzamna limits             # show the default CPU / memory / time limits
itzamna check <file>       # dry run: load and validate a binary without executing it
```
