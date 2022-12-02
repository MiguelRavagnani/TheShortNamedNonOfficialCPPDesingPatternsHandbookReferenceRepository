# Factory

This one looks very circumstantial, but is great if you want to show off.

This pattern is a nice way to hide some implementation for derived classes. We can blend it with other patterns, like
singleton, for instance control, count and so on.

It's kind of cool if yout want a complicated, but safe (and stylish) way to create objects by runtime.

Great if you are afraid of "new"

## Examples

 - Example 1 - Really basic, client-creator like 
 - Example 2 - Way more complex, with some extened functions. TRIGGER WARNING: *singleton*

## Building

Make sure you are in this example root directory (TheShortNamedNonOfficialCPPDesingPatternsHandbookReferenceRepository/factory)

Navigate to the desired example

```bash
cd example1

mkdir build

cd build
```

Buit it (you should be inside {REPOSITORY_PWD}/TheShortNamedNonOfficialCPPDesingPatternsHandbookReferenceRepository/example1/build)

```bash
cmake ..
make
```

## References

[refactoring.guru](https://refactoring.guru/design-patterns/factory-method)

[Mike Shah](https://youtube.com/watch?v=vAmDQKeC99g&ab_channel=MikeShah)