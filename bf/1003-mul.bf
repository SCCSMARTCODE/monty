,       ; Read the first digit
,
>       ; Move to the first digit
[       ; Start the multiplication loop
    -   ; Subtract 1 from the first digit
    >   ; Move to the second digit
    +   ; Add 1 to the second digit
    <   ; Move back to the first digit
]       ; End the loop when the first digit reaches 0
>       ; Move to the second digit
[       ; Start the loop to move the result to the first cell
    -   ; Subtract 1 from the second digit
    >   ; Move to the result cell
    +   ; Add 1 to the result cell
    <   ; Move back to the second digit
]       ; End the loop when the second digit reaches 0
.       ; Print the result
,       ; Print a new line
