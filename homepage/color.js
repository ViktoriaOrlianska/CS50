function ChangeRedColor()
{
    document.getElementById("bg").style.backgroundColor = "#EF4943"
}

function ChangeGreenColor()
{
    document.getElementById("bg").style.backgroundColor = "#6ACD4F"
}

function ChangeBlueColor()
{
    document.getElementById("bg").style.backgroundColor = "#4F8ACD"
}

function selection()
{
    let choice = document.getElementById("choice").value

    if (choice == 1)
    {
        document.querySelector("#message").style.fontWeight = "bold"
    }

    else if (choice == 2)
    {
        document.querySelector("#message").style.fontStyle= "italic"
    }

    else if (choice == 3)
    {
        document.querySelector("#message").style.textDecoration = "underline"
    }

}
