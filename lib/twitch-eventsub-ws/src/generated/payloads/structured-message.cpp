// WARNING: This file is automatically generated. Any changes will be lost.
#include "twitch-eventsub-ws/chrono.hpp"  // IWYU pragma: keep
#include "twitch-eventsub-ws/detail/errors.hpp"
#include "twitch-eventsub-ws/detail/variant.hpp"  // IWYU pragma: keep
#include "twitch-eventsub-ws/payloads/structured-message.hpp"

#include <boost/json.hpp>

namespace chatterino::eventsub::lib::chat {

boost::json::result_for<Cheermote, boost::json::value>::type tag_invoke(
    boost::json::try_value_to_tag<Cheermote> /* tag */,
    const boost::json::value &jvRoot)
{
    if (!jvRoot.is_object())
    {
        EVENTSUB_BAIL_HERE(error::Kind::ExpectedObject);
    }
    const auto &root = jvRoot.get_object();

    const auto *jvprefix = root.if_contains("prefix");
    if (jvprefix == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto prefix = boost::json::try_value_to<String>(*jvprefix);

    if (prefix.has_error())
    {
        return prefix.error();
    }

    static_assert(
        std::is_trivially_copyable_v<
            std::remove_reference_t<decltype(std::declval<Cheermote>().bits)>>);
    const auto *jvbits = root.if_contains("bits");
    if (jvbits == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto bits = boost::json::try_value_to<int>(*jvbits);

    if (bits.has_error())
    {
        return bits.error();
    }

    static_assert(
        std::is_trivially_copyable_v<
            std::remove_reference_t<decltype(std::declval<Cheermote>().tier)>>);
    const auto *jvtier = root.if_contains("tier");
    if (jvtier == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto tier = boost::json::try_value_to<int>(*jvtier);

    if (tier.has_error())
    {
        return tier.error();
    }

    return Cheermote{
        .prefix = std::move(prefix.value()),
        .bits = bits.value(),
        .tier = tier.value(),
    };
}

boost::json::result_for<Emote, boost::json::value>::type tag_invoke(
    boost::json::try_value_to_tag<Emote> /* tag */,
    const boost::json::value &jvRoot)
{
    if (!jvRoot.is_object())
    {
        EVENTSUB_BAIL_HERE(error::Kind::ExpectedObject);
    }
    const auto &root = jvRoot.get_object();

    const auto *jvid = root.if_contains("id");
    if (jvid == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto id = boost::json::try_value_to<String>(*jvid);

    if (id.has_error())
    {
        return id.error();
    }

    const auto *jvemoteSetID = root.if_contains("emote_set_id");
    if (jvemoteSetID == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto emoteSetID = boost::json::try_value_to<String>(*jvemoteSetID);

    if (emoteSetID.has_error())
    {
        return emoteSetID.error();
    }

    return Emote{
        .id = std::move(id.value()),
        .emoteSetID = std::move(emoteSetID.value()),
    };
}

boost::json::result_for<Mention, boost::json::value>::type tag_invoke(
    boost::json::try_value_to_tag<Mention> /* tag */,
    const boost::json::value &jvRoot)
{
    if (!jvRoot.is_object())
    {
        EVENTSUB_BAIL_HERE(error::Kind::ExpectedObject);
    }
    const auto &root = jvRoot.get_object();

    const auto *jvuserID = root.if_contains("user_id");
    if (jvuserID == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto userID = boost::json::try_value_to<String>(*jvuserID);

    if (userID.has_error())
    {
        return userID.error();
    }

    const auto *jvuserName = root.if_contains("user_name");
    if (jvuserName == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto userName = boost::json::try_value_to<String>(*jvuserName);

    if (userName.has_error())
    {
        return userName.error();
    }

    const auto *jvuserLogin = root.if_contains("user_login");
    if (jvuserLogin == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto userLogin = boost::json::try_value_to<String>(*jvuserLogin);

    if (userLogin.has_error())
    {
        return userLogin.error();
    }

    return Mention{
        .userID = std::move(userID.value()),
        .userName = std::move(userName.value()),
        .userLogin = std::move(userLogin.value()),
    };
}

boost::json::result_for<Text, boost::json::value>::type tag_invoke(
    boost::json::try_value_to_tag<Text> /* tag */,
    const boost::json::value & /* jvRoot */)
{
    return Text{};
}

boost::json::result_for<MessageFragment, boost::json::value>::type tag_invoke(
    boost::json::try_value_to_tag<MessageFragment> /* tag */,
    const boost::json::value &jvRoot)
{
    if (!jvRoot.is_object())
    {
        EVENTSUB_BAIL_HERE(error::Kind::ExpectedObject);
    }
    const auto &root = jvRoot.get_object();

    const auto *jvtext = root.if_contains("text");
    if (jvtext == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto text = boost::json::try_value_to<String>(*jvtext);

    if (text.has_error())
    {
        return text.error();
    }

    const auto *jvinnerTag = root.if_contains("type");
    if (jvinnerTag == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto innerTagRes =
        boost::json::try_value_to<boost::json::string>(*jvinnerTag);
    if (innerTagRes.has_error())
    {
        return innerTagRes.error();
    }
    std::string_view innerTag = *innerTagRes;
    decltype(std::declval<MessageFragment>().inner) inner;
    if (innerTag == Text::TAG)
    {
        inner.emplace<Text>();
    }
    else if (innerTag == Cheermote::TAG)
    {
        const auto *innerVal = root.if_contains(detail::fieldFor<Cheermote>());
        if (!innerVal)
        {
            EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
        }
        auto innerCheermote = boost::json::try_value_to<Cheermote>(*innerVal);
        if (innerCheermote.has_error())
        {
            return innerCheermote.error();
        }
        inner.emplace<Cheermote>(std::move(innerCheermote.value()));
    }
    else if (innerTag == Emote::TAG)
    {
        const auto *innerVal = root.if_contains(detail::fieldFor<Emote>());
        if (!innerVal)
        {
            EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
        }
        auto innerEmote = boost::json::try_value_to<Emote>(*innerVal);
        if (innerEmote.has_error())
        {
            return innerEmote.error();
        }
        inner.emplace<Emote>(std::move(innerEmote.value()));
    }
    else if (innerTag == Mention::TAG)
    {
        const auto *innerVal = root.if_contains(detail::fieldFor<Mention>());
        if (!innerVal)
        {
            EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
        }
        auto innerMention = boost::json::try_value_to<Mention>(*innerVal);
        if (innerMention.has_error())
        {
            return innerMention.error();
        }
        inner.emplace<Mention>(std::move(innerMention.value()));
    }
    else
    {
        EVENTSUB_BAIL_HERE(error::Kind::UnknownVariant);
    }

    return MessageFragment{
        .text = std::move(text.value()),
        .inner = std::move(inner),
    };
}

boost::json::result_for<Message, boost::json::value>::type tag_invoke(
    boost::json::try_value_to_tag<Message> /* tag */,
    const boost::json::value &jvRoot)
{
    if (!jvRoot.is_object())
    {
        EVENTSUB_BAIL_HERE(error::Kind::ExpectedObject);
    }
    const auto &root = jvRoot.get_object();

    const auto *jvtext = root.if_contains("text");
    if (jvtext == nullptr)
    {
        EVENTSUB_BAIL_HERE(error::Kind::FieldMissing);
    }

    auto text = boost::json::try_value_to<String>(*jvtext);

    if (text.has_error())
    {
        return text.error();
    }

    std::vector<MessageFragment> vfragments;
    const auto *jvfragments = root.if_contains("fragments");
    if (jvfragments != nullptr && !jvfragments->is_null())
    {
        auto fragments =
            boost::json::try_value_to<std::vector<MessageFragment>>(
                *jvfragments);
        if (fragments.has_error())
        {
            return fragments.error();
        }
        else
        {
            vfragments = std::move(fragments.value());
        }
    }

    return Message{
        .text = std::move(text.value()),
        .fragments = std::move(vfragments),
    };
}

}  // namespace chatterino::eventsub::lib::chat
