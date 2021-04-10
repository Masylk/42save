if [ "$AUTOINDEX" == "off" ]
       then echo "auto-index off\n" && sed -Ei "s/autoindex on/autoindex off/" /etc/nginx/sites-available/localhost
fi
