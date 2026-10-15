# Contributing to `hardware.inc`

## Making changes

Open a pull request against `master` for each change, unless it is a breaking change meant for an upcoming major version (see [Major releases](#major-releases) below).

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

### Minor and patch releases

Minor and patch releases are made directly from `master`.

1. Open a release pull request against `master`, titled after the version (e.g. "Version 5.3.0"), that:
   - updates `HARDWARE_INC_VERSION` in `hardware.inc` to the new version;
   - adds an entry to `HISTORY.md` with the version, release date, and contributors, listing the changes since the last release;
   - summarizes in its description the changes on `master` since the last release, linking to the relevant pull requests (`git log vX.Y.Z..master`, with the previous release's tag, is a good starting point).
2. Once it is approved and merged, tag the merge commit on `master` (e.g. `v5.3.0`).
3. Publish a GitHub release for the tag, using the `HISTORY.md` entry as its release notes.

### Major releases

Major releases collect breaking changes on a version branch with a fixed lifespan, in parallel with the changes being merged to `master`.

1. **Open the version branch.**
   Create a branch from `master` named after the upcoming version (e.g. `release/v6.0.0`; avoid reusing a tag name like `v6.0.0-rc1`, which makes git refs ambiguous).
   Breaking changes for the new major version are merged into this branch through pull requests targeting it, instead of `master`.
   Non-breaking changes keep going to `master` as usual; merge `master` into the version branch periodically to keep it up to date.
2. **Release a candidate.**
   When the version branch is ready, update `HARDWARE_INC_VERSION` and `HISTORY.md` on it for the RC version (e.g. `6.0.0-rc1`).
   Tag that commit (e.g. `v6.0.0-rc1`), publish it as a **prerelease** on GitHub, and announce it.
3. **Wait for the grace period.**
   The version branch stays open for a fixed grace period (about one month) to collect feedback and last-minute changes.
   Further release candidates (e.g. `v6.0.0-rc2`) can be released from the branch in the same way if needed.
4. **Open the release pull request.**
   Once the grace period ends, open a pull request from the version branch into `master`, titled after the version (e.g. "Version 6.0.0").
   Even though the grace period has expired, this gives maintainers a last look at everything that will get shipped.
   The pull request:
   - updates `HARDWARE_INC_VERSION` in `hardware.inc` to the final version;
   - finalizes the `HISTORY.md` entry with the version, release date, and contributors;
   - summarizes in its description all the changes since the last release, linking to the relevant pull requests.
5. **Release.**
   Once the pull request is approved and merged, delete the version branch, tag the merge commit on `master` (e.g. `v6.0.0`), and publish a GitHub release for the tag, using the `HISTORY.md` entry as its release notes.
