enabled = get_option('enabled')
disabled = get_option('disabled')
foreach challenge : enabled
    if challenge not in disabled
        subdir(challenge)
    endif
endforeach