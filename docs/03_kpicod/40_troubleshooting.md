---
content_title: Kpicod Troubleshooting
---

## How to solve the error "Failed to lock access to wallet directory; is another `kpicod` running"?

Since `clpico` may auto-launch an instance of `kpicod`, it is possible to end up with multiple instances of `kpicod` running. That can cause unexpected behavior or the error message above.

To fix this issue, you can terminate all running `kpicod` instances and restart `kpicod`. The following command will find and terminate all instances of `kpicod` running on the system:

```sh
pkill kpicod
```
