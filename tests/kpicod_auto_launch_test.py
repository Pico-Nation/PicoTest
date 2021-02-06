#!/usr/bin/env python3

# This script tests that clpico launches kpicod automatically when kpicod is not
# running yet.

import subprocess


def run_clpico_wallet_command(command: str, no_auto_kpicod: bool):
    """Run the given clpico command and return subprocess.CompletedProcess."""
    args = ['./programs/clpico/clpico']

    if no_auto_kpicod:
        args.append('--no-auto-kpicod')

    args += 'wallet', command

    return subprocess.run(args,
                          check=False,
                          stdout=subprocess.DEVNULL,
                          stderr=subprocess.PIPE)


def stop_kpicod():
    """Stop the default kpicod instance."""
    run_clpico_wallet_command('stop', no_auto_kpicod=True)


def check_clpico_stderr(stderr: bytes, expected_match: bytes):
    if expected_match not in stderr:
        raise RuntimeError("'{}' not found in {}'".format(
            expected_match.decode(), stderr.decode()))


def kpicod_auto_launch_test():
    """Test that kpico auto-launching works but can be optionally inhibited."""
    stop_kpicod()

    # Make sure that when '--no-auto-kpicod' is given, kpicod is not started by
    # clpico.
    completed_process = run_clpico_wallet_command('list', no_auto_kpicod=True)
    assert completed_process.returncode != 0
    check_clpico_stderr(completed_process.stderr, b'Failed to connect to kpicod')

    # Verify that kpicod auto-launching works.
    completed_process = run_clpico_wallet_command('list', no_auto_kpicod=False)
    if completed_process.returncode != 0:
        raise RuntimeError("Expected that kpicod would be started, "
                           "but got an error instead: {}".format(
                               completed_process.stderr.decode()))
    check_clpico_stderr(completed_process.stderr, b'launched')


try:
    kpicod_auto_launch_test()
finally:
    stop_kpicod()
