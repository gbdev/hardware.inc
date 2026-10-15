# Contributing to `hardware.inc`

## Making changes

All development happens on the `master` branch.
Open a pull request against `master` for each change; there are no long-lived version branches.

Pull requests do **not** need to update the embedded version number in `hardware.inc` or the change log in `HISTORY.md`.
Those are updated together in a dedicated release pull request (see below), so `master` may contain unreleased changes at any time.
Use a [tagged release](https://github.com/gbdev/hardware.inc/releases) if you need a stable version.

## Versioning

We follow [semantic versioning](https://semver.org).
Breaking changes increase the major version, backwards-compatible changes (typically new additions) only increase the minor version, and bug fixes (including changes to the comments) only increase the patch level.
(An example of a breaking change is when `hardware.inc` 4.0 updated its syntax for compatibility with RGBDS 0.5.0, breaking compatibility with older RGBDS versions.
Renaming or removing a constant is also a breaking change.)

When a constant is renamed, consider adding the old name to `hardware_compat.inc` so existing projects can keep building.

## Release process

### 1. Release candidate (for major versions)

Releases with breaking changes go through a release candidate first, so users have a chance to try them and give feedback before they are final.
Minor and patch releases may skip this step.

1. Open a pull request against `master` that:
   - updates `HARDWARE_INC_VERSION` in `hardware.inc` to the RC version (e.g. `6.0.0-rc1`);
   - adds an entry for the RC version to `HISTORY.md`, listing the changes since the last release.
2. Once it is merged, tag the resulting `master` commit (e.g. `v6.0.0-rc1`) and publish it as a **prerelease** on GitHub.
3. Announce the RC and wait for a grace period (a few weeks) for comments.

During the grace period, development continues on `master` as usual.
Fixes and further changes are simply merged into `master`; there is no separate RC branch to port them to.
If significant changes are made, a further RC (e.g. `v6.0.0-rc2`) can be released the same way.

### 2. Release pull request

Every release, whether or not it had a release candidate, is made through an explicit pull request.
Even when an RC's grace period has expired, this gives maintainers a last look at everything that will get shipped.

Open a pull request against `master`, titled after the version (e.g. "Version 6.0.0"), that:

- updates `HARDWARE_INC_VERSION` in `hardware.inc` to the new version;
- adds (or finalizes the RC's) entry in `HISTORY.md` with the version, release date, and contributors, listing all the changes since the last release;
- summarizes in its description the changes on `master` since the last release (or since the last RC), linking to the relevant pull requests.

`git log vX.Y.Z..master` (with the previous release's tag) is a good starting point for that list.

### 3. Publishing

Once the release pull request is approved and merged:

1. Tag the merge commit on `master` (e.g. `v6.0.0`).
2. Publish a GitHub release for the tag, using the `HISTORY.md` entry as its release notes.
