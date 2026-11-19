# OpenTLOS

An attempt to decompile both "The Legend of Spyro" entries:

- A New Beginning (contains debug symbols inside itself)
- The Eternal Night

## How It Will Be Done

Using any external tools + decomp.dev objdiff live feedback similar to seen in GodHand repo locally, it attempts a byte-for-byte match, using A New Beginning as a base because ANB and TEN share the same Krome Engine, and the same codebase with minor differences.

User's device is a MacBook Pro 2021, M1 Max, so Apple Silicon, and macOS 27.2

User also had a repo where they tried to mod ANB's elemental powers to TEN on a PS2 disc, but ultimately left the progress stale. Now that there's a chance for a quick decomp (where you first get as much code out as possible with any possible tool, like ghidra, Wii/GameCube homebrew scene, and community-made tools to assist). Once you have all the code in what was the original language tooling used, then you can finally work out the kinks to start byte-matching for 100% accuracy.

xsyetopz/GodHand repo is a good example. You **must not** re-invent the wheel. Any external tooling, even from the supposed game code, must not be decompiled unless it *literally* does not exist anywhere on the internet, and archives. No giant monolithic structures either. Try to follow the game's idiomatic debug-symbol-based locations as close as possible.

We got two discs:

- `/Users/krystian/CodeProjects/xsyetopz/OpenTLOS/discs/Legend of Spyro, The - A New Beginning (USA).rvz` (CONTAINS DEBUG SYMBOLS EMBEDDED!)
- `/Users/krystian/CodeProjects/xsyetopz/OpenTLOS/discs/Legend of Spyro, The - The Eternal Night (USA).rvz`
