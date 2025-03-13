# 42_ft_printf
This project consists in recreating the printf() function. Aiming for it to behave as close to the original as possible.

---

### Supported Conversions:
- `%c`: character
- `%s`: string
- `%p`: pointer in hexadecimal format
- `%d`: decimal number
- `%i`: integer
- `%u`: unsigned decimal number
- `%x`: hexadecimal number (lowercase)
- `%X`: hexadecimal number (uppercase)
- `%%`: percent symbol

### Bonus (Not Implemented)
- Manage any combination of the following flags: `-0.` and the field minimum width
under all conversions.
- Manage all the following flags: `# +` (space)

---

### How to use?
Compile the `main.c` file with the ft_printf library and run the program:

```bash
cc main.c libftprintf.a
```

---

### Testing
In the mains folder, there are some tests in different main functions, easier to run and test on early stages. Below are some other testers I'm using to make sure everything is correct.

| Tester | Author     |
| :-------- | :------- |
| [printfTester](https://github.com/Tripouille/printfTester) | `Tripouille` |
| [ft_printf_test](https://github.com/cacharle/ft_printf_test) | `cacharle` |
