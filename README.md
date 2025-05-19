# `hardware.inc`

## Game Boy hardware definitions

`hardware.inc` has been the standard include file containing Game Boy hardware definitions for use in [RGBDS](https://rgbds.gbdev.io) projects for over 20 years.

The file was originally created by Jeff Frohwein in 1997.
Although Jeff tried to track version updates with a rudimentary change log at the top of the file, people have made small changes throughout the years, often without bumping the version number.

This repository has become the official reference for `hardware.inc`, using [@AntonioND](https://github.com/AntonioND)'s fork as the baseline.

## Contributing

This repository's `master` branch should be considered the production version.
Each commit represents a new release, so each one should update the embedded version number in `hardware.inc` and the change log in `HISTORY.md`.

We follow [semantic versioning](https://semver.org).
Breaking changes increase the major version, backwards-compatible changes (typically new additions) only increase the minor version, and bug fixes (including changes to the comments) only increase the patch level.
(An example of a breaking change is when `hardware.inc` 4.0 updated its syntax for compatibility with RGBDS 0.5.0, breaking compatibility with older RGBDS versions.)

## Contributors

* Jones (created the original `hardware.inc`, now lost)
* Carsten Sørensen (whose ideas Jeff based his file on)
* Jeff Frohwein
* AntonioND
* BlitterObjectBob, tobiasvl, ISSOtm, Rangi42, avivace, Eievui, QuinnPainter, rondnelson99, daid, Hacktix, sukus21, alvaro-cuesta, basxto
* Probably lots of other people who have added to the file throughout the years
